from Lista import buscarRotas

class Main():

  while True:
    x = input("""\nQuer adicio no inicio ou no fim?\t 
                1. Inicio
                2. Fim
                3. Sair do codigo""")
    
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

    escolha = input("""\nQual o dia da semana?\t 
                1. Segunda-feira
                2. Terça-feira
                3. Quarta-feira
                4. Quinta-feira
                5. Sexta-feira  
                    """)
    escolha = int(escolha)
    match escolha:
      case 1: 
        material = "Segunda-feira"
      case 2: 
        material = "Terça-feira"
      case 3: 
        material = "Quarta-feira"
      case 4: 
        material = "Quinta-feira"
      case 5: 
        material = "Sexta-feira"
      case _: 
        material = "Erro"

    if material != "Erro":
        print("paia")
        lista = buscarRotas(material,inicio)
        for rodizio in lista:
          rodizio.imprimir()
        break
  