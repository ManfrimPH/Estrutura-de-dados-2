class Node:
    def __init__(self, id, material, endereco):
        self.id = id
        self.material = material
        self.endereco = endereco
        self.proximo = None

    def __str__(self):
        return f"[{self.id}] {self.material} - {self.endereco}"

class ListaSimplesmenteEncadeada:
    def __init__(self):
        self.head = None
        self.tail = None

    def inserir(self, id, material, endereco):
        novo = Node(id, material, endereco)
        if self.head is None:
            self.head = self.tail = novo
        else:
            self.tail.proximo = novo
            self.tail = novo

    def imprimir(self):
        atual = self.head
        while atual:
            print(atual)
            atual = atual.proximo

def carregar_coletas_de_arquivo(caminho_arquivo, lista, tipo_material):
    with open(caminho_arquivo, 'r', encoding='utf-8') as arquivo:
        for linha in arquivo:
            linha = linha.strip()
            if linha:
                partes = linha.split(';')
                if len(partes) == 3 and partes[1] == tipo_material:
                    id = int(partes[0])
                    material = partes[1]
                    endereco = partes[2]
                    lista.inserir(id, material, endereco)