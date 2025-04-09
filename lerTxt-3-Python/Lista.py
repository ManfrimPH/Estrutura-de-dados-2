from Rodizio import Rodizio

def buscarRotas(tipo,Inicio=True):

  lista = []

  with open ('rodizio_de_veiculos.txt', 'r', encoding="utf-8") as arquivo:
    for linha in arquivo:
      dados = linha.split(';')
      if tipo not in dados[1]:
        continue
      else:
        temp = Rodizio(dados[0],dados[1],dados[2])
        if Inicio == True:
          lista.insert(0,temp)
        else:  
          lista.append(temp)
  return lista