#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emergencias_urbanas.h"

void inicializarFilaPrioridade(FilaPrioridade** fila) {
    *fila = (FilaPrioridade*)malloc(sizeof(FilaPrioridade));
    if (*fila == NULL) {
        printf("Erro: Falha na alocação de memória\n");
        exit(1);
    }
    (*fila)->frente = NULL;
}

void enfileirarChamado(FilaPrioridade** fila, const char* descricao, int prioridade) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro: Falha na alocação de memória\n");
        return;
    }

    strncpy(novoNo->dado.descricao, descricao, sizeof(novoNo->dado.descricao) - 1);
    novoNo->dado.prioridade = prioridade;

    if ((*fila)->frente == NULL || prioridade < (*fila)->frente->dado.prioridade) {
        novoNo->proximo = (*fila)->frente;
        (*fila)->frente = novoNo;
        return;
    }

    No* noAtual = (*fila)->frente;
    while (noAtual->proximo != NULL && noAtual->proximo->dado.prioridade <= prioridade) {
        noAtual = noAtual->proximo;
    }

    novoNo->proximo = noAtual->proximo;
    noAtual->proximo = novoNo;
}

int desenfileirarChamado(FilaPrioridade** fila) {
    if ((*fila)->frente == NULL) {
        printf("Fila vazia!\n");
        return 0;
    }

    No* noRemovido = (*fila)->frente;
    (*fila)->frente = (*fila)->frente->proximo;

    printf("Chamado removido: %s (Prioridade: %d)\n", 
           noRemovido->dado.descricao, noRemovido->dado.prioridade);
    free(noRemovido);
    return 1;
}

void exibirChamados(FilaPrioridade* fila) {
    if (fila->frente == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    printf("\nChamados na fila:\n");
    No* noAtual = fila->frente;
    while (noAtual != NULL) {
        printf("Descrição: %s - Prioridade: %d\n", 
               noAtual->dado.descricao, noAtual->dado.prioridade);
        noAtual = noAtual->proximo;
    }
    printf("\n");
}

void liberarMemoriaPrioridade(FilaPrioridade** fila) {
    No* noAtual = (*fila)->frente;
    while (noAtual != NULL) {
        No* noTemp = noAtual;
        noAtual = noAtual->proximo;
        free(noTemp);
    }
    free(*fila);
    *fila = NULL;
} 