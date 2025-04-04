#include <stdlib.h>
#include <stdio.h>
#include "no.h"

void inserirInicio(No** lista, int valor) {
	No* novo = (No*)malloc(sizeof(No));
	
	if(novo) {
		novo->valor = valor;
		novo->proximo = *lista;
		*lista = novo;
	} else {
		printf("Erro ao alocar memória.\n");
	}
}

void inserirFim(No** lista, int valor) {
	No* aux, *novo = (No*)malloc(sizeof(No));
	
	printf("Endereço da lista no.c: %p", &lista);
	printf("\nConteudo da lista no.c: \n");
	//imprimir(lista);
	
	if(novo) {
		novo->valor = valor;
		novo->proximo = NULL;
		
		if(*lista == NULL) {
			*lista = novo;
		} else {
			aux = *lista;
			while(aux->proximo)
				aux = aux->proximo;
			aux->proximo = novo;
		}
	} else {
		printf("Erro ao alocar memória.\n");
	}
	
	printf("\nValor do novo nó: %d", novo->valor);
	printf("\nProximo endereço do novo nó: %p", novo->proximo);
	printf("\nEndereço do novo %p", &novo);
	printf("\nConteudo do novo: %d", novo->valor);
}

void inserirMeio(No** lista, int valor, int valorReferencia) {
	No* aux, *novo = (No*)malloc(sizeof(No));
	
	if(novo) {
		novo->valor = valor;
		
		if(*lista == NULL) {
			novo->proximo = NULL;
			*lista = novo;
		} else {
			aux = *lista;
			while(aux->valor != valorReferencia && aux->proximo)
				aux = aux->proximo;
			novo->proximo = aux->proximo;
			aux->proximo = novo;
		}
	} else {
		printf("Erro ao alocar memória.\n");
	}
}

void inserirOrdenado(No** lista, int valor) {
	No* aux, *novo = (No*)malloc(sizeof(No));
	
	if(novo) {
		novo->valor = valor;
		
		if(*lista == NULL) {
			novo->proximo = NULL;
			*lista = novo;
		} else if(novo->valor < (*lista)->valor) {
			novo->proximo = *lista;
			*lista = novo;
		} else {
			aux = *lista;
			while(aux->proximo && novo->valor > aux->proximo->valor)
				aux = aux->proximo;
			novo->proximo = aux->proximo;
			aux->proximo = novo;
		}
	} else {
		printf("Erro ao alocar memória.\n");
	}
}

void imprimir(No* no) {
	printf("\nLista: ");
	while(no) {
		printf("%d ", no->valor);
		no = no->proximo;
	}
	printf("\n\n");
}




