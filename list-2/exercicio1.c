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

int calcularFatorial(int n) {
    Pilha p;
    inicializarPilha(&p);
    int resultado = 1;
    
    for (int i = n; i >= 1; i--) {
        empilhar(&p, i);
    }
    
    while (p.topo >= 0) {
        resultado *= desempilhar(&p);
    }
    
    return resultado;
}

int main() {
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    
    printf("Fatorial de %d = %d\n", numero, calcularFatorial(numero));
    return 0;
} 