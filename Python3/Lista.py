class Node:
    def __init__(self, id, dia_semana, horarios):
        self.id = id
        self.dia_semana = dia_semana
        self.horarios = horarios  # lista de horários
        self.proximo = None
        self.anterior = None

    def __str__(self):
        horarios_formatados = ' | '.join(self.horarios)
        return f"[{self.id}] {self.dia_semana} - Horários: {horarios_formatados}"

class ListaDuplamenteEncadeada:
    def __init__(self):
        self.head = None
        self.tail = None

    def inserir(self, id, dia_semana, horarios):
        novo = Node(id, dia_semana, horarios)
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

def carregar_agendamentos_de_arquivo(caminho_arquivo, lista, dia_filtro=None):
    with open(caminho_arquivo, 'r', encoding='utf-8') as arquivo:
        for linha in arquivo:
            linha = linha.strip()
            if linha:
                partes = linha.split(';')
                if len(partes) == 3:
                    id = partes[0]
                    dia_semana = partes[1]
                    horarios = [h.strip() for h in partes[2].split(',')]
                    if dia_filtro is None or dia_semana == dia_filtro:
                        lista.inserir(id, dia_semana, horarios)

