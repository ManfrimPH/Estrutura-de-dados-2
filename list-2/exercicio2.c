#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    float dados[MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

void empilhar(Pilha *p, float valor) {
    if (p->topo < MAX - 1) {
        p->dados[++p->topo] = valor;
    }
}

float desempilhar(Pilha *p) {
    if (p->topo >= 0) {
        return p->dados[p->topo--];
    }
    return -1;
}

float avaliarExpressao(char *expressao) {
    Pilha p;
    inicializarPilha(&p);
    char *token = strtok(expressao, " ");
    
    while (token != NULL) {
        if (isdigit(token[0])) {
            empilhar(&p, atof(token));
        } else {
            float b = desempilhar(&p);
            float a = desempilhar(&p);
            
            switch (token[0]) {
                case '+': empilhar(&p, a + b); break;
                case '-': empilhar(&p, a - b); break;
                case '*': empilhar(&p, a * b); break;
                case '/': empilhar(&p, a / b); break;
            }
        }
        token = strtok(NULL, " ");
    }
    
    return desempilhar(&p);
}

int main() {
    char expressao[100];
    printf("Digite a expressao pos-fixa (numeros e operadores separados por espaco): ");
    fgets(expressao, sizeof(expressao), stdin);
    
    printf("Resultado: %.2f\n", avaliarExpressao(expressao));
    return 0;
} 