#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

/*

2. Normalização de Valores
Contextualização: Um software de análise precisa normalizar valores entre 0 e 1.
Comando: Implemente um programa que normaliza valores armazenados em um vetor dinâmico.
Especificação Técnica: O programa deve alocar dinamicamente um vetor, encontrar o maior valor e dividir todos os elementos por ele.
Pseudocódigo:
- Alocar dinamicamente um vetor
- Criar uma função que encontra o maior valor
- Criar uma função que divide todos os valores pelo maior

*/

void imprimir_dividido(float *vet, int tam){
	
	int i;
	
	for(i=0 ; i<tam ; i++){
		
		printf("%.2f - ", vet[i]);
	}	
}


void imprimir(float *vet, int tam){
	
	int i;

	for(i=0 ; i<tam ; i++){
		
		printf("%.0f - ", vet[i]);
	}
	
}


int main(){
	setlocale(LC_ALL, "Portuguese");
	
	srand(time(NULL));
	
	int tam, i;
	float *vet, maior;
	
	printf("\nQual o tamanho do vetor? : ");
	scanf("%i", &tam);
	
	vet = malloc(tam * sizeof(float));
	
	if(!vet){
		printf("\n\nNão foi possível alocar a memória");
	}
	else{
		
		for(i=0 ; i<tam ; i++){
			
			vet[i] = rand() %(tam + 20) + 1;
			
			if(i == 0){
				maior = vet[i];
			}
			else{
				if (maior < vet[i]){
					maior = vet[i];
				}
			}	
		}
		
		
		printf("\n\nVetor original:\n");
		imprimir(vet, tam);
		
		
		for(i=0 ; i<tam ; i++){
			vet[i] = vet[i] / maior;
		}
		
		
		printf("\n\nMaior valor: %.0f", maior);
		printf("\nVetor dividido pelo maior valor:\n");
		
		imprimir_dividido(vet, tam);		
	}
	
	
	free(vet);
	
	return 0;
}
