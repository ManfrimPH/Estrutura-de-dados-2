from Descarte import Descarte

def buscarDescartes(tipo):

  lista = []

  with open ('pontos_de_descarte.txt', 'r', encoding="utf-8") as arquivo:
    for linha in arquivo:
      dados = linha.split(';')
      if dados[1] != tipo:
        continue
      else:
        temp = Descarte(dados[0],dados[1],dados[2])
        lista.append(temp)
  return lista