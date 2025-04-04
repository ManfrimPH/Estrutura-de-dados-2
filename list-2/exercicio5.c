#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

void empilhar(Pilha *p, int valor) {
    if (p->topo < MAX - 1) {
        p->dados[++p->topo] = valor;
    }
}

int desempilhar(Pilha *p) {
    if (p->topo >= 0) {
        return p->dados[p->topo--];
    }
    return -1;
}

int main() {
    Pilha terminal;
    inicializarPilha(&terminal);
    int opcao, numeroOnibus;
    
    do {
        printf("\n1 - Registrar chegada de onibus\n");
        printf("2 - Registrar saida de onibus\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Numero do onibus: ");
                scanf("%d", &numeroOnibus);
                empilhar(&terminal, numeroOnibus);
                printf("Onibus %d registrado\n", numeroOnibus);
                break;
                
            case 2:
                numeroOnibus = desempilhar(&terminal);
                if (numeroOnibus != -1) {
                    printf("Onibus %d saiu do terminal\n", numeroOnibus);
                } else {
                    printf("Terminal vazio\n");
                }
                break;
        }
    } while (opcao != 3);
    
    return 0;
} 