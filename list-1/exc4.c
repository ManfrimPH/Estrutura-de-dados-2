#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

/*

4. Troca Dinâmica de Variáveis
Contextualização: Um sistema precisa trocar os valores de duas variáveis sem uso de variáveis auxiliares.
Comando: Desenvolva um programa que utilize ponteiros para realizar a troca dinâmica de valores.
Especificação Técnica: O programa deve alocar duas variáveis dinamicamente e trocá-las via ponteiros.
Pseudocódigo:
- Alocar dinamicamente duas variáveis
- Criar uma função que realiza a troca
- Exibir antes e depois da troca

*/

void imprimir(int *vet, int tam, char* txt){
	
	int i;
	
	printf("%s", txt);
	
	for(i=0 ; i<tam ; i++){
		printf("%i - ", vet[i]);
	}
	
}


void inverter(int *v1, int *v2, int tam){
	
	int i;
	
	for(i=0 ; i<tam ; i++){
		
		if(v1[i] != v2[i]){
			
			v1[i] = v1[i] + v2[i];
			v2[i] = v1[i] - v2[i];
			v1[i] = v1[i] - v2[i];
		
		}
	}
}


int main(){
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	int *vet1, *vet2, tam, i;
	
	printf("\n\tTrocar dois vetores sem usar variável auxiliar\n\n");
	
	printf("Tamanho do vetor: ");
	scanf("%i", &tam);
	
	vet1 = malloc(tam * sizeof(int));
	vet2 = malloc(tam * sizeof(int));
	
	for(i=0 ; i<tam ; i++){
		vet1[i] = rand()%50 + 1;
		vet2[i] = rand()%50 + 1;		
	}
	
	system("cls");
	printf("\n\tVetores originais:\n\n");
	
	imprimir(vet1, tam, "Vetor 1: ");
	printf("\n");
	imprimir(vet2, tam, "Vetor 2: ");
	
	
	printf("\n\n\tVetores invertidos:\n\n");
	
	inverter(vet1, vet2, tam);
	
	imprimir(vet1, tam, "Vetor 1: ");
	printf("\n");
	imprimir(vet2, tam, "Vetor 2: ");
	
	
	printf("\n\n");
	free(vet1);
	free(vet2);
	

	return 0;
	
}
