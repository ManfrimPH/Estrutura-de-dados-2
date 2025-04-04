#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>


/*

5. Ajuste de Notas Escolares
Contextualiza��o: Um professor precisa arredondar as notas de seus alunos para evitar injusti�as.
Comando: Implemente um programa que ajuste as notas dinamicamente.
Especifica��o T�cnica: O programa deve alocar dinamicamente um vetor e ajustar as notas com base em um crit�rio.
Pseudoc�digo:
- Alocar dinamicamente um vetor de notas
- Criar uma fun��o que arredonda as notas
- Exibir antes e depois do ajuste

*/


double dar_notas(){
	
	double num, dec;
	
	num = rand()%10;
	dec = rand()%10;
	
	return num + (dec/10);
	
}

double arredondar(double num){
	
	if( (num - (int)num) >= 0.5 ){
		return (int)num + 1;
	}
	
	return (int)num;
}


int main(){
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	double *vet, num;
	int tam, i;
	
	
	printf("\n\tQuantos alunos na turma? : ");
	scanf("%i", &tam);
	 
	vet = malloc(tam * sizeof(double));
	
	for(i=0 ; i<tam ; i++){
		
		vet[i] = dar_notas();
		
	}
	
	
	system("cls");
	
	printf("\n\tNotas originais:\n");
	for(i=0 ; i<tam ; i++){
		printf("%.1lf - ", vet[i]);
	}
	
	printf("\n\nNotas arredondadas:\n");
	for(i=0 ; i<tam ; i++){ 
	
		printf("%.1lf - ", arredondar(vet[i]));
		
	}
	
	free(vet);
	
	return 0;
}
