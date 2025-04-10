from Lista import ListaDuplamenteEncadeada, carregar_agendamentos_de_arquivo


def main():
    escolha = input("""\nQual o dia da semana?\t 
                1. Segunda-feira
                2. Terça-feira
                3. Quarta-feira
                4. Quinta-feira
                5. Sexta-feira  
                    """)

    try:
        escolha = int(escolha)
    except ValueError:
        print("Entrada inválida. Digite um número de 1 a 5.")
        return

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

    if material == "Erro":
        print("Opção inválida.")
        return

    print("Buscando rotas para:", material)

    lista = ListaDuplamenteEncadeada()
    carregar_agendamentos_de_arquivo("rotas_de_transportes.txt", lista, material)

    print("Listagem da esquerda para a direita:\n")
    lista.imprimir_direita()

    print("\nListagem da direita para a esquerda:\n")
    lista.imprimir_esquerda()

if __name__ == "__main__":
    main()
