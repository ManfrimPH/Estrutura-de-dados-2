#ifndef TRANSPORTE_PUBLICO_H
#define TRANSPORTE_PUBLICO_H

typedef struct Passageiro {
    char nome[50];
    char destino[50];
} Passageiro;

typedef struct No {
    Passageiro dado;
    struct No* proximo;
} No;

typedef struct Fila {
    No* frente;
    No* traseira;
} Fila;

void inicializarFila(Fila** fila);
void enfileirarPassageiro(Fila** fila, const char* nome, const char* destino);
int desenfileirarPassageiro(Fila** fila);
void exibirPassageiros(Fila* fila);
void liberarMemoria(Fila** fila);

#endif 