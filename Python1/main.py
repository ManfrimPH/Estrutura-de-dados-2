from Lista import ListaSimplesmenteEncadeada, carregar_coletas_de_arquivo

def main():
    escolha = input("""\nQual material de lixo vc quer buscar ?\t 
                1. Metal
                2. Plastico 
                3. Papel
                4. Vidro 
                5. Eletronicos
                6. Desisto\n""")
    try:
        escolha = int(escolha)
    except ValueError:
        print("Entrada inválida. Digite um número de 1 a 5.")
        return

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

    if material == "Erro":
        print("Opção inválida.")
        return

    print("Buscando rotas para:", material)

    lista = ListaSimplesmenteEncadeada()
    carregar_coletas_de_arquivo("rotas_de_transportes.txt", lista, material)

    print("Listagem:\n")
    lista.imprimir()

if __name__ == "__main__":
    main()
