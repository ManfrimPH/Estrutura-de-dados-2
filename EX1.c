#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>

void ajustarTemp (float *temperaturas, int tamanho){
  for (int i = 0; i < tamanho; i++){
    if(*(temperaturas + i) < 0){
      *(temperaturas + i) = 0;
    }else if (*(temperaturas + i) > 70){
        *(temperaturas + i) = 70;
    }
  }
}

int main(){
	setlocale(LC_ALL, "Portuguese");
  
  int n;
  printf("Quantas temperaturas você quer anotar?");
  scanf("%d", &n);

  float *temperatura = (float *)malloc(n * sizeof(float));
  if (temperatura == NULL){
    printf("Erro ao alocar a memoria\n");
  }

  printf("Fale os valores:\n");
  for(int i = 0; i < n; i++){
    printf("Temperatura %d:", i+1);
    scanf("%f", temperatura + i);
  }
	
  ajustarTemp(temperatura, n);

  printf("Valores ajustados:\n");
  for(int i = 0; i < n; i++){
    printf("%.2f    -    ", *(temperatura + i));
  }

  free(temperatura);

  system("pause");

  return 1;

}