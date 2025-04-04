#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

/*

10. Manipula��o Din�mica de Matrizes
Contextualiza��o: Um sistema de mapeamento precisa armazenar dinamicamente uma matriz de dados de localiza��o.
Comando: Desenvolva um programa que armazene uma matriz alocada dinamicamente e permita a manipula��o de seus valores.
Especifica��o T�cnica: O programa deve alocar uma matriz dinamicamente, preench�-la e exibi-la com aritm�tica de ponteiros.
Pseudoc�digo:
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
			printf("Insira o valor a ser colocado na posi��o %dx%d: ", i+1, j+1);
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
