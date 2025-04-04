#include <stdio.h>
#include "lista.h"

int main() {
    Lista* lista = criarLista();
    int opcao, valor;
    
    do {
        printf("\n=== Menu da Lista Encadeada ===\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Buscar elemento\n");
        printf("4. Imprimir lista\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserir(lista, valor);
                printf("Elemento inserido com sucesso!\n");
                break;

            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                if (remover(lista, valor)) {
                    printf("Elemento removido com sucesso!\n");
                } else {
                    printf("Elemento não encontrado na lista.\n");
                }
                break;

            case 3:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                No* resultado = buscar(lista, valor);
                if (resultado != NULL) {
                    printf("Elemento %d encontrado na lista!\n", valor);
                } else {
                    printf("Elemento %d não encontrado na lista.\n", valor);
                }
                break;

            case 4:
                imprimirLista(lista);
                break;

            case 5:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 5);

    destruirLista(lista);
    return 0;
} 