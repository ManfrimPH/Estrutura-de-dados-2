// main.c
#include <stdio.h>
#include "rodizio.h"

int main() {
    ListaCircular* lista = inicializarLista();
    char criterio[15];
    int opcao;
    
    do {
        printf("\n1 - Exibir veiculos\n");
        printf("2 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("Digite o dia da semana: ");
                scanf("%s", criterio);
                carregarArquivo(lista, criterio);
                exibirVeiculos(lista);
                break;
            case 2:
                liberarLista(lista);
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 2);
    
    return 0;
}
