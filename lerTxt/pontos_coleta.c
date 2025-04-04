#include "pontos_coleta.h"

Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    if (lista != NULL) {
        lista->inicio = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

void destruirLista(Lista* lista) {
    if (lista == NULL) return;
    
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(lista);
}

void inserirNoInicio(Lista* lista, PontoColeta ponto) {
    if (lista == NULL) return;
    
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) return;
    
    novo->ponto = ponto;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
}

void imprimirLista(Lista* lista) {
    if (lista == NULL || lista->inicio == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    
    printf("\nPontos de Coleta na Lista:\n");
    printf("------------------------\n");
    
    No* atual = lista->inicio;
    while (atual != NULL) {
        printf("Número: %d\n", atual->ponto.numero);
        printf("Tipo: %s\n", atual->ponto.tipo);
        printf("Endereço: %s\n", atual->ponto.endereco);
        printf("------------------------\n");
        atual = atual->proximo;
    }
}

int compararStringsLista(const char* str1, const char* str2) {
    char str1_copia[MAX_TIPO];
    char str2_copia[MAX_TIPO];
    
    strncpy(str1_copia, str1, MAX_TIPO - 1);
    strncpy(str2_copia, str2, MAX_TIPO - 1);
    str1_copia[MAX_TIPO - 1] = '\0';
    str2_copia[MAX_TIPO - 1] = '\0';
    
    for (int i = 0; str1_copia[i]; i++) {
        if (str1_copia[i] >= 'A' && str1_copia[i] <= 'Z')
            str1_copia[i] += 32;
    }
    
    for (int i = 0; str2_copia[i]; i++) {
        if (str2_copia[i] >= 'A' && str2_copia[i] <= 'Z')
            str2_copia[i] += 32;
    }
    
    return strcmp(str1_copia, str2_copia) == 0;
}

void buscarPorTipo(Lista* lista, const char* tipo) {
    if (lista == NULL || lista->inicio == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    
    printf("\nPontos de Coleta do tipo %s:\n", tipo);
    printf("------------------------\n");
    
    No* atual = lista->inicio;
    int encontrados = 0;
    
    while (atual != NULL) {
        if (compararStringsLista(atual->ponto.tipo, tipo)) {
            printf("Número: %d\n", atual->ponto.numero);
            printf("Tipo: %s\n", atual->ponto.tipo);
            printf("Endereço: %s\n", atual->ponto.endereco);
            printf("------------------------\n");
            encontrados++;
        }
        atual = atual->proximo;
    }
    
    if (encontrados == 0) {
        printf("Nenhum ponto de coleta encontrado para o tipo %s\n", tipo);
    }
} 