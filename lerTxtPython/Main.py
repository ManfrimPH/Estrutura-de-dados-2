from Lista import buscarDescartes

class Main():

  while True:

    escolha = input("""\nQual material de lixo vc quer buscar ?\t 
                1. Metal
                2. Plastico 
                3. Papel
                4. Vidro 
                5. Eletronicos
                6. Desisto\n""")
    escolha = int(escolha)
    match escolha:
      case 1: 
        material = "Metal"
      case 2: 
        material = "Plastico"
      case 3: 
        material = "Papel"
      case 4: 
        material = "Vidro"
      case 5: 
        material = "Eletronicos"
      case 6:
        material = "Desisto"
      case _: 
        material = "Erro"

    if material != "Erro" and material != "Desisto":
        lista = buscarDescartes(material)
        for descarte in lista:
          descarte.imprimir()
        break
    elif material == "Desisto":
      break
    else:
      print("Escolheu o valor errado, tenta de novo!")
  