#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "pontos_coleta.h"

#define MAX_LINHA 100

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

PontoColeta lerLinhaArquivo(const char* linha) {
    PontoColeta ponto;
    char* token;
    char linha_copia[MAX_LINHA];
    
    strcpy(linha_copia, linha);
    
    token = strtok(linha_copia, ";");
    ponto.numero = atoi(token);
    
    token = strtok(NULL, ";");
    if (token != NULL) {
        strncpy(ponto.tipo, token, MAX_TIPO - 1);
        ponto.tipo[MAX_TIPO - 1] = '\0';
    } else {
        ponto.tipo[0] = '\0';
    }
    
    token = strtok(NULL, ";");
    if (token != NULL) {
        strncpy(ponto.endereco, token, MAX_ENDERECO - 1);
        ponto.endereco[MAX_ENDERECO - 1] = '\0';
    } else {
        ponto.endereco[0] = '\0';
    }
    
    return ponto;
}

int compararStrings(const char* str1, const char* str2) {
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

int main() {
    #ifdef _WIN32
    system("chcp 65001");
    #endif
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    FILE* arquivo = fopen("pontos_coleta.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    
    Lista* lista = criarLista();
    if (lista == NULL) {
        printf("Erro ao criar a lista!\n");
        fclose(arquivo);
        return 1;
    }
    
    char linha[MAX_LINHA];
    char tipo_busca[MAX_TIPO];
    
    printf("Digite o tipo de material para buscar (Plastico, Vidro, Eletronicos, Papel ou Metal): ");
    fgets(tipo_busca, MAX_TIPO, stdin);
    tipo_busca[strcspn(tipo_busca, "\n")] = 0;
    
    while (fgets(linha, MAX_LINHA, arquivo) != NULL) {
        linha[strcspn(linha, "\n")] = 0;
        
        PontoColeta ponto = lerLinhaArquivo(linha);
        
        if (compararStrings(ponto.tipo, tipo_busca)) {
            inserirNoInicio(lista, ponto);
        }
    }
    
    buscarPorTipo(lista, tipo_busca);
    
    destruirLista(lista);
    fclose(arquivo);
    
    return 0;
}
