#include <stdio.h>
#include <stdlib.h>

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

float calcularMedia(Pilha *p) {
    float soma = 0;
    int quantidade = p->topo + 1;
    
    for (int i = 0; i <= p->topo; i++) {
        soma += p->dados[i];
    }
    
    return soma / quantidade;
}

int main() {
    Pilha p;
    inicializarPilha(&p);
    int n;
    float medicao;
    
    printf("Quantas medicoes deseja inserir? ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Digite a medicao %d: ", i + 1);
        scanf("%f", &medicao);
        empilhar(&p, medicao);
    }
    
    printf("Media de consumo: %.2f\n", calcularMedia(&p));
    return 0;
} 