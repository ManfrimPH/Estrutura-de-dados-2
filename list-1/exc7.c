#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void ajustarValor(int* ptr_valor) {
    (*ptr_valor) *= 1.5;  
}


int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	
	int valor_original = 100;
    
    int *ptr_valor = malloc(sizeof(int));
    int *ptr_novo = malloc(sizeof(int));
    
    if (ptr_valor == NULL || ptr_novo == NULL) {
        printf("\nErro na alocação de memória.\n");
        return 1;
    }
    
    *ptr_novo = valor_original;
    
    printf("Valor original:           %d\n", valor_original);
    printf("Valor antes da operação:  %d\n", *ptr_novo);
    
    ajustarValor(ptr_novo);
    
    printf("\nValor após ajuste de 50%%: %d\n", *ptr_novo);
    
    free(ptr_valor);
    free(ptr_novo);
    
    return 0;

}
