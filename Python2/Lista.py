class Node:
    def __init__(self, id, rota, transporte, local):
        self.id = id
        self.rota = rota
        self.transporte = transporte
        self.local = local
        self.proximo = None
        self.anterior = None

    def __str__(self):
        return f"[{self.id}] {self.rota} - {self.transporte} - {self.local}"

class ListaDuplamenteEncadeada:
    def __init__(self):
        self.head = None
        self.tail = None

    def inserir(self, id, rota, transporte, local):
        novo = Node(id, rota, transporte, local)
        if self.head is None:
            self.head = self.tail = novo
        else:
            self.tail.proximo = novo
            novo.anterior = self.tail
            self.tail = novo

    def imprimir_direita(self):
        atual = self.head
        while atual:
            print(atual)
            atual = atual.proximo

    def imprimir_esquerda(self):
        atual = self.tail
        while atual:
            print(atual)
            atual = atual.anterior

def carregar_rotas_de_arquivo(caminho_arquivo, lista, tipo):
    with open(caminho_arquivo, 'r', encoding='utf-8') as arquivo:
        for linha in arquivo:
            linha = linha.strip()
            if linha:
                partes = linha.split(';')
                if len(partes) == 4 and partes[3] == tipo:
                    id = int(partes[0])
                    rota = partes[1]
                    transporte = partes[2]
                    local = partes[3]
                    lista.inserir(id, rota, transporte, local)
