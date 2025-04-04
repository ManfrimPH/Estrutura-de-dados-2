#ifndef ROTAS_H
#define ROTAS_H

// Estrutura para armazenar uma rota
typedef struct Rota {
    int id;
    char nome[100];
    char tipo[20];
    char regiao[50];
    struct Rota* proximo;
} Rota;

// Funções para manipulação da lista
Rota* criarRota(int id, const char* nome, const char* tipo, const char* regiao);
void adicionarRota(Rota** lista, Rota* nova);
void carregarRotas(Rota** lista, const char* filtro);
void mostrarRotas(Rota* lista);
void liberarRotas(Rota** lista);
void adicionarNovaRota(Rota** lista);

#endif 