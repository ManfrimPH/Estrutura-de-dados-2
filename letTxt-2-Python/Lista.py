from Rota import Rota

def buscarRotas(tipo,Inicio=True):

  lista = []

  with open ('rotas_de_transportes.txt', 'r', encoding="utf-8") as arquivo:
    for linha in arquivo:
      dados = linha.split(';')
      if tipo not in dados[3]:
        continue
      else:
        temp = Rota(dados[0],dados[1],dados[2],dados[3])
        if Inicio == True:
          lista.insert(0,temp)
        else:  
          lista.append(temp)
  return lista