#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

/*

6. Atualização Dinâmica de Pontuação (ODS 11 - Comunidades Sustentáveis)
Contextualização: Em uma iniciativa para incentivar o transporte sustentável, um aplicativo atribui pontos aos usuários por quilômetros percorridos de bicicleta. O sistema precisa atualizar a pontuação dinamicamente.
Comando: Desenvolva um programa que utilize uma variável alocada dinamicamente para armazenar a pontuação e a atualize após cada viagem.
Especificação Técnica: O programa deve alocar dinamicamente uma variável de pontuação e modificá-la via ponteiro.
Pseudocódigo:
- Alocar dinamicamente uma variável de pontuação
- Criar um procedimento que aumenta o valor da pontuação
- Exibir antes e depois da modificação


*/


int main(){
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	double viagem, pontos, novo_tamanho, *vet = NULL;
	int opc, i, tam=0;
	
	printf("\n\tSistema de pontuação para viagens de bicicletas (trabalhando no nome ainda)\n\n");

	do{
		printf("\n\t1 -- Nova viagem\n\t2 -- Imprimir pontuação\n\n\t0 -- Sair\n");
		scanf("%i", &opc);
		
		switch(opc){
			case 1:
				novo_tamanho = (tam+1) * sizeof(double);
				vet = realloc(vet, novo_tamanho);
				
				if(!vet){
					printf("\n\nErro ao alocar a memória.\n");
					free(vet);
					return 1;
				}
			
				printf("\n\nEntre quantos quilêmtros foram percorridos: ");
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
						printf("%i° viagem - %.1lf km\n", i+1, vet[i]);
						
						pontos += (vet[i] * 10);
					}
					
					printf("\n\tPontos = %.1lf\n\n", pontos);
					
				}
				
				break;
			
			default:
				if(opc != 0){
					printf("\nOpção incorreta.\n");
				}
				break;
		}
	
		printf("\n\n\n");
		
	} while(opc!=0);

	free(vet);
	printf("\n\nBye bye");
	return 0;

}
