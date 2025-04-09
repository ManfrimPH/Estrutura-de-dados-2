class Rota:
    def __init__(self, id: int, nome: str, tipo: str, regiao: str):
        self.id = id
        self.nome = nome
        self.tipo = tipo
        self.regiao = regiao

    def imprimir(self):
        print(f"ID: {self.id} | Nome: {self.nome} | Tipo: {self.tipo} | Regiao: {self.regiao}")