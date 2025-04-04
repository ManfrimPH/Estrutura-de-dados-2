#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

/*

6. Atualiza��o Din�mica de Pontua��o (ODS 11 - Comunidades Sustent�veis)
Contextualiza��o: Em uma iniciativa para incentivar o transporte sustent�vel, um aplicativo atribui pontos aos usu�rios por quil�metros percorridos de bicicleta. O sistema precisa atualizar a pontua��o dinamicamente.
Comando: Desenvolva um programa que utilize uma vari�vel alocada dinamicamente para armazenar a pontua��o e a atualize ap�s cada viagem.
Especifica��o T�cnica: O programa deve alocar dinamicamente uma vari�vel de pontua��o e modific�-la via ponteiro.
Pseudoc�digo:
- Alocar dinamicamente uma vari�vel de pontua��o
- Criar um procedimento que aumenta o valor da pontua��o
- Exibir antes e depois da modifica��o


*/


int main(){
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	double viagem, pontos, novo_tamanho, *vet = NULL;
	int opc, i, tam=0;
	
	printf("\n\tSistema de pontua��o para viagens de bicicletas (trabalhando no nome ainda)\n\n");

	do{
		printf("\n\t1 -- Nova viagem\n\t2 -- Imprimir pontua��o\n\n\t0 -- Sair\n");
		scanf("%i", &opc);
		
		switch(opc){
			case 1:
				novo_tamanho = (tam+1) * sizeof(double);
				vet = realloc(vet, novo_tamanho);
				
				if(!vet){
					printf("\n\nErro ao alocar a mem�ria.\n");
					free(vet);
					return 1;
				}
			
				printf("\n\nEntre quantos quil�mtros foram percorridos: ");
				scanf("%lf", &vet[tam]);
			
				printf("\n\nViagem registrada!\n");
				tam++;
				
				break;
				
			case 2:
				if(!vet){
					printf("\n\nSem viagens registradas ainda\n");
				}
				else{
					printf("\n");
					pontos = 0;
					
					for(i=0 ; i<tam ; i++){
						printf("%i� viagem - %.1lf km\n", i+1, vet[i]);
						
						pontos += (vet[i] * 10);
					}
					
					printf("\n\tPontos = %.1lf\n\n", pontos);
					
				}
				
				break;
			
			default:
				if(opc != 0){
					printf("\nOp��o incorreta.\n");
				}
				break;
		}
	
		printf("\n\n\n");
		
	} while(opc!=0);

	free(vet);
	printf("\n\nBye bye");
	return 0;

}
