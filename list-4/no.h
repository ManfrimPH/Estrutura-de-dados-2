#ifndef NO_H
#define NO_H

typedef struct No {
	int valor;
	struct No* proximo;
} No;

void inserirInicio(No** lista, int valor);
void inserirFim(No** lista, int valor);
void inserirMeio(No** lista, int valor, int valorReferencia);
void inserirOrdenado(No** lista, int valor);
void imprimir(No* no);

#endif
