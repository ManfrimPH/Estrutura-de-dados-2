# letTxt-2-Python/main.py
import rotas
import os

def limpar_tela():
    os.system('cls' if os.name == 'nt' else 'clear')

def menu_principal():
    script_dir = os.path.dirname(__file__) if "__file__" in locals() else "."
    arquivo_rotas_path = os.path.join(script_dir, rotas.NOME_ARQUIVO)

    while True:
        print("\n=== Menu Principal ===")
        print("1. Buscar rotas")
        print("2. Adicionar nova rota")
        print("3. Sair")
        escolha = input("Escolha uma opção: ")

        if escolha == '1':
            limpar_tela()
            filtro = input("Digite o tipo ou região para filtrar (ou deixe em branco para todas): ")
            lista_rotas_encontradas = rotas.carregar_rotas(filtro, arquivo_rotas_path)
            rotas.mostrar_rotas(lista_rotas_encontradas)
            input("\nPressione Enter para continuar...")
            limpar_tela()
        elif escolha == '2':
            limpar_tela()
            rotas.adicionar_nova_rota(arquivo_rotas_path)
            input("\nPressione Enter para continuar...")
            limpar_tela()
        elif escolha == '3':
            print("Saindo...")
            break
        else:
            limpar_tela()
            print("Opção inválida. Tente novamente.")
            input("\nPressione Enter para continuar...")
            limpar_tela()

if __name__ == "__main__":
    limpar_tela()
    menu_principal() 