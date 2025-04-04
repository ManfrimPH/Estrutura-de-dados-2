// veiculo.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rodizio.h"

ListaCircular* inicializarLista() {
    ListaCircular* lista = (ListaCircular*)malloc(sizeof(ListaCircular));
    lista->inicio = NULL;
    lista->quantidade = 0;
    return lista;
}

void inserirVeiculo(ListaCircular* lista, char* placa, char* dia, char* horario) {
    Veiculo* novo = (Veiculo*)malloc(sizeof(Veiculo));
    strcpy(novo->placa, placa);
    strcpy(novo->dia_semana, dia);
    strcpy(novo->horario, horario);

    if (lista->inicio == NULL) {
        lista->inicio = novo;
        novo->proximo = novo;
    } else {
        novo->proximo = lista->inicio->proximo;
        lista->inicio->proximo = novo;
    }
    lista->quantidade++;
}

void carregarArquivo(ListaCircular* lista, char* criterio) {
    FILE* arquivo = fopen("rodizio_de_veiculos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    char linha[100];
    char placa[8], dia[15], horario[30];
    
    while (fgets(linha, sizeof(linha), arquivo)) {
        sscanf(linha, "%[^;];%[^;];%[^\n]", placa, dia, horario);
        
        if (strstr(dia, criterio) != NULL) {
            inserirVeiculo(lista, placa, dia, horario);
        }
    }

    fclose(arquivo);
}

void exibirVeiculos(ListaCircular* lista) {
    if (lista->inicio == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    Veiculo* atual = lista->inicio;
    do {
        printf("Placa: %s\n", atual->placa);
        printf("Dia: %s\n", atual->dia_semana);
        printf("Horario: %s\n\n", atual->horario);
        atual = atual->proximo;
    } while (atual != lista->inicio);
}

void liberarLista(ListaCircular* lista) {
    if (lista->inicio == NULL) {
        free(lista);
        return;
    }

    Veiculo* atual = lista->inicio->proximo;
    Veiculo* proximo;
    
    while (atual != lista->inicio) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    
    free(lista->inicio);
    free(lista);
}
