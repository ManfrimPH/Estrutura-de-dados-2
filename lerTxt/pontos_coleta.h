#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TIPO 20
#define MAX_ENDERECO 50

typedef struct {
    int numero;
    char tipo[MAX_TIPO];
    char endereco[MAX_ENDERECO];
} PontoColeta;

typedef struct No {
    PontoColeta ponto;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    int tamanho;
} Lista;

Lista* criarLista();
void destruirLista(Lista* lista);
void inserirNoInicio(Lista* lista, PontoColeta ponto);
void imprimirLista(Lista* lista);
void buscarPorTipo(Lista* lista, const char* tipo);

#endif 