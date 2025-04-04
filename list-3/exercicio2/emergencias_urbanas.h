#ifndef EMERGENCIAS_URBANAS_H
#define EMERGENCIAS_URBANAS_H

typedef struct Chamado {
    char descricao[100];
    int prioridade;  
} Chamado;

typedef struct No {
    Chamado dado;
    struct No* proximo;
} No;

typedef struct FilaPrioridade {
    No* frente;
} FilaPrioridade;

void inicializarFilaPrioridade(FilaPrioridade** fila);

void enfileirarChamado(FilaPrioridade** fila, const char* descricao, int prioridade);

int desenfileirarChamado(FilaPrioridade** fila);

void exibirChamados(FilaPrioridade* fila);

void liberarMemoriaPrioridade(FilaPrioridade** fila);

#endif 