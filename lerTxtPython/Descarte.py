class Descarte:

  def __init__(self, id, tipo, endereco):
    self.id = id
    self.tipo = tipo
    self.endereco = endereco

  def imprimir(self):
    print(f"{self.id} || {self.tipo} || {self.endereco}")