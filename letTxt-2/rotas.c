#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rotas.h"

Rota* criarRota(int id, const char* nome, const char* tipo, const char* regiao) {
    Rota* nova = (Rota*)malloc(sizeof(Rota));
    if (nova == NULL) {
        printf("Erro ao alocar memoria\n");
        return NULL;
    }
    
    nova->id = id;
    strcpy(nova->nome, nome);
    strcpy(nova->tipo, tipo);
    strcpy(nova->regiao, regiao);
    nova->proximo = NULL;
    
    return nova;
}

void adicionarRota(Rota** lista, Rota* nova) {
    if (*lista == NULL) {
        *lista = nova;
        return;
    }
    
    Rota* atual = *lista;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = nova;
}

void carregarRotas(Rota** lista, const char* filtro) {
    FILE* arquivo = fopen("rotas_de_transportes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        return;
    }
    
    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
        int id;
        char nome[100], tipo[20], regiao[50];
        
        sscanf(linha, "%d;%[^;];%[^;];%[^\n]", &id, nome, tipo, regiao);
        
        if (strstr(tipo, filtro) != NULL || strstr(regiao, filtro) != NULL) {
            Rota* nova = criarRota(id, nome, tipo, regiao);
            adicionarRota(lista, nova);
        }
    }
    
    fclose(arquivo);
}

void mostrarRotas(Rota* lista) {
    if (lista == NULL) {
        printf("Nenhuma rota encontrada\n");
        return;
    }
    
    Rota* atual = lista;
    while (atual != NULL) {
        printf("ID: %d | Nome: %s | Tipo: %s | Regiao: %s\n",
               atual->id, atual->nome, atual->tipo, atual->regiao);
        atual = atual->proximo;
    }
}

void liberarRotas(Rota** lista) {
    Rota* atual = *lista;
    while (atual != NULL) {
        Rota* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *lista = NULL;
}

void adicionarNovaRota(Rota** lista) {
    int id;
    char nome[100], tipo[20], regiao[50];
    
    printf("\nDigite o ID: ");
    scanf("%d", &id);
    getchar();
    
    printf("Digite o nome: ");
    scanf("%[^\n]", nome);
    getchar();
    
    printf("Digite o tipo: ");
    scanf("%[^\n]", tipo);
    getchar();
    
    printf("Digite a regiao: ");
    scanf("%[^\n]", regiao);
    getchar();
    
    Rota* nova = criarRota(id, nome, tipo, regiao);
    adicionarRota(lista, nova);
    
    FILE* arquivo = fopen("rotas_de_transportes.txt", "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "%d;%s;%s;%s\n", id, nome, tipo, regiao);
        fclose(arquivo);
        printf("Rota adicionada com sucesso!\n");
    }
} 