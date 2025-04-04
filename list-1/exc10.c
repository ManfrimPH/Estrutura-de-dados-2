#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

/*

10. Manipulação Dinâmica de Matrizes
Contextualização: Um sistema de mapeamento precisa armazenar dinamicamente uma matriz de dados de localização.
Comando: Desenvolva um programa que armazene uma matriz alocada dinamicamente e permita a manipulação de seus valores.
Especificação Técnica: O programa deve alocar uma matriz dinamicamente, preenchê-la e exibi-la com aritmética de ponteiros.
Pseudocódigo:
- Alocar dinamicamente uma matriz nxm
- Preencher valores
- Criar um procedimento que exibe os valores


*/

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int **matriz;
	int i, j, l, c;
	
	printf("- Tamanhos da matriz -\n");
	printf("Insira quantas linhas: ");
	scanf(" %d", &l);
	printf("Insira quantas colunas: ");
	scanf(" %d", &c);
	printf("\n");
	
	matriz = malloc(l * sizeof (int*));
	
	for(i = 0; i < l; i++){
		matriz[i] = malloc(c * sizeof (int));
	}
	
	for(i = 0; i < l; i++){
		for(j = 0; j < c; j++){
			printf("Insira o valor a ser colocado na posição %dx%d: ", i+1, j+1);
			scanf("%d", &matriz[i][j]);
		}
	}
	system("cls");
	printf("Mostrando a matriz...\n\n");
	Sleep(1500);
	system("cls");
	
	for(i = 0; i < l; i++){
		for(j = 0; j < c; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	
	for(i=0 ; i<l ; i++){
		free(matriz[i]);
	}
	free(matriz);
	
	printf("\n\n\n");
}
