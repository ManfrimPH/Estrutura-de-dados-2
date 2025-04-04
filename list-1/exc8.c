/*8. Manipulação Dinâmica de Vetores
Contextualização: Uma empresa precisa armazenar e processar grandes volumes de dados numéricos dinamicamente.
Comando: Implemente um programa que aloque um vetor dinamicamente e manipule seus elementos utilizando aritmética de ponteiros.
Especificação Técnica: O programa deve criar um vetor dinamicamente e acessá-lo usando ponteiros.
Pseudocódigo:
- Alocar dinamicamente um vetor de tamanho n
- Preencher o vetor com valores
- Criar um procedimento que percorre e exibe os valores
*/

#include<stdio.h>
#include<stdlib.h>

void exibirVetor(int *vet, int tamanho){
	int i;
	
	for(i=0; i < tamanho; i++){
		printf("%d ", *(vet + i));
	}
	printf("\n");
}
//---------------------------------------------
int main(){
	int n;
	
	printf("Insira o tamanho do vetor: ");
	scanf("%d", &n);
	printf("\n");
	
	//---------------------------------------------
	
	int *vet = (int*) malloc(n * sizeof(int));
	if(vet == NULL){
		printf("Erro ao alocar memória");
		return 1;
	}
	
	//---------------------------------------------
	
	printf("Insira %d valores: ", n);
	int i;
	for(i=0; i<n; i++){
		scanf("%d", (vet+i));
	}
	
	printf("\n\n");
	
	//---------------------------------------------
	
	printf("Valores no vetor: ");
	exibirVetor(vet, n);
	
	free(vet);
}
