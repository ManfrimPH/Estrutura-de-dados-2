#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

void empilhar(Pilha *p, char valor) {
    if (p->topo < MAX - 1) {
        p->dados[++p->topo] = valor;
    }
}

char desempilhar(Pilha *p) {
    if (p->topo >= 0) {
        return p->dados[p->topo--];
    }
    return '\0';
}

int validarExpressao(char *expressao) {
    Pilha p;
    inicializarPilha(&p);
    
    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(' || expressao[i] == '[' || expressao[i] == '{') {
            empilhar(&p, expressao[i]);
        } else if (expressao[i] == ')' || expressao[i] == ']' || expressao[i] == '}') {
            char topo = desempilhar(&p);
            if ((expressao[i] == ')' && topo != '(') ||
                (expressao[i] == ']' && topo != '[') ||
                (expressao[i] == '}' && topo != '{')) {
                return 0;
            }
        }
    }
    
    return p.topo == -1;
}

int main() {
    char expressao[100];
    printf("Digite a expressao: ");
    scanf("%s", expressao);
    
    if (validarExpressao(expressao)) {
        printf("Expressao valida\n");
    } else {
        printf("Expressao invalida\n");
    }
    return 0;
} 