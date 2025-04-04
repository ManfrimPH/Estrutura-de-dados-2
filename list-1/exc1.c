#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

/*
1. Ajuste Din�mico de Temperaturas (ODS 11 - Cidades Sustent�veis)
Contextualiza��o: Em uma cidade inteligente, sensores registram temperaturas ao longo do dia. Um sistema precisa ajustar esses valores para corrigir poss�veis erros.
Comando: Desenvolva um programa que utilize um vetor alocado dinamicamente para armazenar as temperaturas e corrija varia��es extremas.
Especifica��o T�cnica: O programa deve alocar dinamicamente um vetor de temperaturas, processar os valores via ponteiros e ajust�-los conforme um crit�rio de estabilidade.
Pseudoc�digo:
- Alocar dinamicamente um vetor de temperaturas
- Criar uma fun��o que recebe o vetor e ajusta valores extremos
- Exibir os valores corrigidos
*/


void imprimir(int *vet, int men, int mai, int tam){
	printf("\n\nVetor ajustado entre os limites %i - %i\n\n", men, mai);
	
	int i;
	
	for(i=0 ; i<tam ; i++){
		
		printf("%i - ", vet[i]);
	}
	
}


int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int i, maior, menor, *vet, tam;
	srand(time(NULL));
	
	printf("\nDefina o intervalo desejado:\nMenor: ");
	scanf("%i", &menor);
	
	printf("\nMaior: ");
	scanf("%i", &maior);
	
	printf("\nDefina o tamanho do vetor: ");
	scanf("%i", &tam);
	
	vet = malloc(tam * sizeof(int));
	
	if(!vet){
		printf("\n\nN�o foi poss�vel alocar a mem�ria");
	}
	else{
		
		for(i=0 ; i<tam ; i++){
			vet[i] = rand() % (maior - menor + 21) + (menor - 10);
			
			if(vet[i] > maior){
				vet[i] = maior;
			}
			
			if(vet[i] < menor){
				vet[i] = menor;
			}
		}
		
		imprimir(vet, menor, maior, tam);
		
	}
	
	free(vet);
	
	return 0;
	
}


