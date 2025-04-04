#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>


/*

3. Modificação Dinâmica de Elementos de Matriz
Contextualização: Uma aplicação precisa modificar elementos específicos de uma matriz com base em um critério.
Comando: Escreva um programa que armazene dinamicamente uma matriz e modifique seus elementos com base em um critério específico.
Especificação Técnica: O programa deve alocar dinamicamente uma matriz, processá-la com ponteiros e alterar elementos que atendam ao critério.
Pseudocódigo:
- Alocar dinamicamente uma matriz
- Criar um procedimento que altera valores conforme um critério
- Exibir a matriz modificada

*/


void imprimir(int **mat, int lin, int col){
	
	int i, j;
	
	for(i=0 ; i<lin ; i++){
		
		for(j=0 ; j<col ; j++){
			printf("%i - ", mat[i][j]);
		}
		
		printf("\n");
		
	}
	
}


void inverter(int **mat, int linha, int coluna){
	
	int **mat_inv, i, j, k, l;
	
	k = linha - 1;
	l = coluna - 1;
	
	mat_inv = malloc( linha * sizeof(int*));
	
	for(i=0 ; i<linha ; i++){
		mat_inv[i] = malloc(coluna * sizeof(int));
	}
	
	for(i=0 ; i<linha ; i++){
		
		for(j=0 ; j<coluna ; j++){
			
			mat_inv[k][l] = mat[i][j];
			l--;
			
		}
		
		l = coluna - 1;
		k--;
		
	}
	
	imprimir(mat_inv, linha, coluna);
	
	for(i=0 ; i<linha ; i++){
		free(mat_inv[i]);
	}
	free(mat_inv);
	
}



int main(){
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	int **mat, linha, coluna, i, j;
	
	printf("\n\tInverter uma matriz:\n\n");
	printf("Quantas linhas: ");
	scanf("%i", &linha);
	
	printf("\nQuantas colunas: ");
	scanf("%i", &coluna);
	
	mat = malloc(linha * sizeof(int*));
	
	for(i=0 ; i<linha ; i++){
		mat[i] = malloc(coluna * sizeof(int));
	}
	
	
	for(i=0 ; i<linha ; i++){
		
		for(j=0 ; j<coluna ; j++){
			mat[i][j] = rand()%50 + 1;
		}
		
	}
	
	system("cls");
	
	printf("\n\tMatriz original:\n\n");
	imprimir(mat, linha, coluna);
	
	printf("\n\n\tMatriz invertida:\n\n");
	inverter(mat, linha, coluna);
	
	for(i=0 ; i<linha ; i++){
		free(mat[i]);
	}
	free(mat);
	
	printf("\n\n");
	
	return 0;	
}
