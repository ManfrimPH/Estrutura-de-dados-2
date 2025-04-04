/*9. Cálculo de Média com Vetor Dinâmico
Contextualização: Um professor deseja calcular dinamicamente a média de notas de seus alunos, permitindo variação no número de alunos.
Comando: Escreva um programa que armazene notas em um vetor dinâmico e calcule a média de forma flexível.
Especificação Técnica: O programa deve alocar dinamicamente um vetor de notas, calcular a média e exibir o resultado.
Pseudocódigo:
- Alocar dinamicamente um vetor de notas
- Criar um procedimento que calcula a média
- Exibir a média
*/

#include<stdio.h>
#include<stdlib.h>

void exibirVetor(int *vet, int tamanho){
	int i;
	
	for(i=0; i < tamanho; i++){
		printf(" %d |", *(vet + i));
	}
	printf("\n");
}
//---------------------------------------------
void calcularMedia(int *vet, int tamanho){
	float soma = 0;
	int i;
	for(i=0; i<tamanho; i++){
		soma += *(vet + i);
	}
	printf("Media: %.2f", soma/tamanho);
}
//---------------------------------------------
int main(){
	int n;
	
	printf("Insira o numero de alunos: ");
	scanf("%d", &n);
	printf("\n");
	
	//---------------------------------------------
	
	int *vet = (int*) malloc(n * sizeof(int));
	if(vet == NULL){
		printf("Erro ao alocar memória");
		return 1;
	}
	
	//---------------------------------------------
	
	printf("Insira %d notas: \n", n);
	int i;
	for(i=0; i<n; i++){
		printf("Nota %d: ", i+1);
		scanf("%d", (vet+i));
		printf("\n");
	}
	
	printf("\n");
	
	//---------------------------------------------
	
	printf("Notas no vetor: ");
	exibirVetor(vet, n);
	printf("\n");
	calcularMedia(vet, n);
	printf("\n");
	
	free(vet);
}
