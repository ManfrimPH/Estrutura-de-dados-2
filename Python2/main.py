from Lista import ListaDuplamenteEncadeada, carregar_rotas_de_arquivo


def main():
    escolha = input("""\nQual o local que você vai? 
        1. Zona Norte
        2. Zona Leste
        3. Zona Oeste
        4. Zona Sul
        5. Centro\n-> """)

    try:
        escolha = int(escolha)
    except ValueError:
        print("Entrada inválida. Digite um número de 1 a 5.")
        return

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

    if material == "Erro":
        print("Opção inválida.")
        return

    print("Buscando rotas para:", material)

    lista = ListaDuplamenteEncadeada()
    carregar_rotas_de_arquivo("rotas_de_transportes.txt", lista, material)

    print("Listagem da esquerda para a direita:\n")
    lista.imprimir_direita()

    print("\nListagem da direita para a esquerda:\n")
    lista.imprimir_esquerda()

if __name__ == "__main__":
    main()
