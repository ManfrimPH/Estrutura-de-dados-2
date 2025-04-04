#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    int tamanho;
} Lista;

// Funções para manipulação da lista
Lista* criarLista();
void destruirLista(Lista* lista);
void inserir(Lista* lista, int valor);
int remover(Lista* lista, int valor);
No* buscar(Lista* lista, int valor);
void imprimirLista(Lista* lista);

#endif 