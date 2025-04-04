#include <stdio.h>
#include "rotas.h"

int main() {
    Rota* lista = NULL;
    int opcao;
    char filtro[50];
    
    do {
        printf("\n=== Menu ===\n");
        printf("1. Buscar rotas\n");
        printf("2. Adicionar rota\n");
        printf("3. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();
        
        switch(opcao) {
            case 1:
                printf("Digite o tipo ou regiao: ");
                scanf("%[^\n]", filtro);
                getchar();
                carregarRotas(&lista, filtro);
                mostrarRotas(lista);
                liberarRotas(&lista);
                break;
                
            case 2:
                adicionarNovaRota(&lista);
                liberarRotas(&lista);
                break;
                
            case 3:
                printf("Saindo...\n");
                break;
                
            default:
                printf("Opcao invalida\n");
        }
    } while(opcao != 3);
    
    return 0;
}

