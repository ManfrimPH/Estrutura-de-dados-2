#include <stdio.h>
#include "emergencias_urbanas.h"

int main() {
    FilaPrioridade* filaChamados;
    inicializarFilaPrioridade(&filaChamados);

    printf("=== Sistema de Atendimento Prioritário para Emergências Urbanas ===\n\n");

    enfileirarChamado(&filaChamados, "Queda de árvore", 2);
    enfileirarChamado(&filaChamados, "Acidente grave", 1);
    enfileirarChamado(&filaChamados, "Falha em semáforo", 3);

    printf("Estado inicial da fila (ordenada por prioridade):");
    exibirChamados(filaChamados);

    printf("\nAtendendo chamado mais prioritário:\n");
    desenfileirarChamado(&filaChamados);

    printf("\nEstado da fila após atendimento:");
    exibirChamados(filaChamados);

    liberarMemoriaPrioridade(&filaChamados);
    return 0;
} 