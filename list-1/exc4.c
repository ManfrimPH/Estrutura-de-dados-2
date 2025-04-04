#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

/*

4. Troca Din�mica de Vari�veis
Contextualiza��o: Um sistema precisa trocar os valores de duas vari�veis sem uso de vari�veis auxiliares.
Comando: Desenvolva um programa que utilize ponteiros para realizar a troca din�mica de valores.
Especifica��o T�cnica: O programa deve alocar duas vari�veis dinamicamente e troc�-las via ponteiros.
Pseudoc�digo:
- Alocar dinamicamente duas vari�veis
- Criar uma fun��o que realiza a troca
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
	
	printf("\n\tTrocar dois vetores sem usar vari�vel auxiliar\n\n");
	
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
