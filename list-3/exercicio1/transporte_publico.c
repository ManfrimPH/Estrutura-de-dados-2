#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transporte_publico.h"

void inicializarFila(Fila** fila) {
    *fila = (Fila*)malloc(sizeof(Fila));
    if (*fila == NULL) {
        printf("Erro: Falha na alocação de memória\n");
        exit(1);
    }
    (*fila)->frente = NULL;
    (*fila)->traseira = NULL;
}

void enfileirarPassageiro(Fila** fila, const char* nome, const char* destino) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro: Falha na alocação de memória\n");
        return;
    }

    strncpy(novoNo->dado.nome, nome, sizeof(novoNo->dado.nome) - 1);
    strncpy(novoNo->dado.destino, destino, sizeof(novoNo->dado.destino) - 1);
    novoNo->proximo = NULL;

    if ((*fila)->traseira == NULL) {
        (*fila)->frente = novoNo;
        (*fila)->traseira = novoNo;
    } else {
        (*fila)->traseira->proximo = novoNo;
        (*fila)->traseira = novoNo;
    }
}

int desenfileirarPassageiro(Fila** fila) {
    if ((*fila)->frente == NULL) {
        printf("Fila vazia!\n");
        return 0;
    }

    No* noRemovido = (*fila)->frente;
    (*fila)->frente = (*fila)->frente->proximo;

    if ((*fila)->frente == NULL) {
        (*fila)->traseira = NULL;
    }

    printf("Passageiro removido: %s - %s\n", noRemovido->dado.nome, noRemovido->dado.destino);
    free(noRemovido);
    return 1;
}

void exibirPassageiros(Fila* fila) {
    if (fila->frente == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    printf("\nPassageiros na fila:\n");
    No* noAtual = fila->frente;
    while (noAtual != NULL) {
        printf("Nome: %s - Destino: %s\n", noAtual->dado.nome, noAtual->dado.destino);
        noAtual = noAtual->proximo;
    }
    printf("\n");
}

void liberarMemoria(Fila** fila) {
    No* noAtual = (*fila)->frente;
    while (noAtual != NULL) {
        No* noTemp = noAtual;
        noAtual = noAtual->proximo;
        free(noTemp);
    }
    free(*fila);
    *fila = NULL;
} 