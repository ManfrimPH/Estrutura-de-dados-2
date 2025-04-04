// veiculo.h
typedef struct Veiculo {
    char placa[8];
    char dia_semana[15];
    char horario[30];
    struct Veiculo* proximo;
} Veiculo;

typedef struct {
    Veiculo* inicio;
    int quantidade;
} ListaCircular;

// Declarações das funções
ListaCircular* inicializarLista();
void inserirVeiculo(ListaCircular* lista, char* placa, char* dia, char* horario);
void carregarArquivo(ListaCircular* lista, char* criterio);
void exibirVeiculos(ListaCircular* lista);
void liberarLista(ListaCircular* lista);
