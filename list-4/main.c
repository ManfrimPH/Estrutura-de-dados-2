#include <stdio.h>
#include <stdlib.h>
#include "no.h"
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	setlocale(LC_ALL, "Portuguese");
	
	int opcao, valor, valorReferencia;
	No *lista = NULL;
	
	do{
		printf("\n0 - Sair\n1 - Inserir no início\n2 - Inserir no fim\n3 - Inserir no meio\n4 - Inserir Ordenado\n5 - Imprimir\n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				printf("Valor: ");
				scanf("%d", &valor);
				inserirInicio(&lista, valor);
				break;
			
			case 2:
				printf("Valor: ");
				scanf("%d", &valor);
				inserirFim(&lista, valor);
				break;
				
			case 3:
				printf("Valor a ser inserido e valor de referência: ");
				scanf("%d%d", &valor, &valorReferencia);
				inserirMeio(&lista, valor, valorReferencia);
				break;
				
			case 4:
				printf("Valor: ");
				scanf("%d", &valor);
				inserirOrdenado(&lista, valor);
				break;
				
			case 5:
				imprimir(lista);
				break;
				
			default:
				if(opcao != 0)
					printf("Opção inválida.\n");
		}
	}while(opcao != 0);
	
	system("pause");
	return 0;
}
