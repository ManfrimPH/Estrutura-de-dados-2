import rodizio
import os

def limpar_tela():
    os.system('cls' if os.name == 'nt' else 'clear')

def menu_principal():
    script_dir = os.path.dirname(__file__) if "__file__" in locals() else "."
    arquivo_rodizio_path = os.path.join(script_dir, rodizio.NOME_ARQUIVO)

    while True:
        print("\n=== Consulta de Rodízio ===")
        print("1 - Consultar por Dia da Semana")
        print("2 - Sair")
        opcao = input("Escolha uma opção: ")

        if opcao == '1':
            limpar_tela()
            dia_semana = input("Digite o dia da semana (ex: Segunda-feira): ")
            if dia_semana:
                veiculos_do_dia = rodizio.carregar_veiculos(dia_semana, arquivo_rodizio_path)
                rodizio.exibir_veiculos(veiculos_do_dia)
            else:
                print("Dia da semana não pode ser vazio.")
            input("\nPressione Enter para continuar...")
            limpar_tela()
        elif opcao == '2':
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