from Lista import buscarRotas

class Main():

  while True:
    x = input("""\nQuer adicio no inicio ou no fim?\t 
                1. Inicio
                2. Fim
                3. Sair do codigo\n""")
    
    match int(x):
      case 1:
        inicio = True
      case 2:
        inicio = False
      case 3:
        break
      case _:
        print("Valor invalido")
        continue

    escolha = input("""\nQual o local que vc vai? ?\t 
                1. Zona Norte
                2. Zona Leste
                3. Zona Oeste
                4. Zona Sul
                5. Centro\n""")
    escolha = int(escolha)
    match escolha:
      case 1: 
        material = "Zona Norte"
      case 2: 
        material = "Zona Leste"
      case 3: 
        material = "Zona Oeste"
      case 4: 
        material = "Zona Sul"
      case 5: 
        material = "Centro"
      case _: 
        material = "Erro"

    if material != "Erro":
        print("paia")
        lista = buscarRotas(material,inicio)
        for rota in lista:
          rota.imprimir()
        break
  