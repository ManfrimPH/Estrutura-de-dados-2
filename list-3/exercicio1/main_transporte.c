#include <stdio.h>
#include "transporte_publico.h"

int main() {
    Fila* filaPassageiros;
    inicializarFila(&filaPassageiros);

    printf("=== Sistema de Gerenciamento de Transporte Público ===\n\n");

    enfileirarPassageiro(&filaPassageiros, "Ana", "Centro");
    enfileirarPassageiro(&filaPassageiros, "Carlos", "Bairro X");
    enfileirarPassageiro(&filaPassageiros, "Maria", "Bairro Y");

    printf("Estado inicial da fila:");
    exibirPassageiros(filaPassageiros);

    printf("\nAtendendo um passageiro:\n");
    desenfileirarPassageiro(&filaPassageiros);

    printf("\nEstado da fila após atendimento:");
    exibirPassageiros(filaPassageiros);

    liberarMemoria(&filaPassageiros);
    return 0;
} 