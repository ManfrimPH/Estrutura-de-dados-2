# letTxt-2-Python/rotas.py
import csv
import os

# Define o nome do arquivo de dados
NOME_ARQUIVO = "rotas_de_transportes.txt"

class Rota:
    """Representa uma rota de transporte."""
    def __init__(self, id: int, nome: str, tipo: str, regiao: str):
        self.id = id
        self.nome = nome
        self.tipo = tipo
        self.regiao = regiao

    def __str__(self):
        return f"ID: {self.id} | Nome: {self.nome} | Tipo: {self.tipo} | Regiao: {self.regiao}"

def carregar_rotas(filtro: str = "", arquivo_path: str = NOME_ARQUIVO) -> list[Rota]:
    """
    Carrega rotas do arquivo CSV, opcionalmente filtrando por tipo ou região.
    Retorna uma lista de objetos Rota.
    """
    rotas_carregadas = []
    try:
        # Garante que o diretório do script seja considerado se o path for relativo
        script_dir = os.path.dirname(__file__) if "__file__" in locals() else "."
        path_completo = os.path.join(script_dir, arquivo_path)

        # Cria o diretório se não existir (necessário se o script for rodado de fora)
        os.makedirs(os.path.dirname(path_completo), exist_ok=True)


        with open(path_completo, 'r', encoding='utf-8', newline='') as arquivo:
            leitor = csv.reader(arquivo, delimiter=';')
            for linha in leitor:
                if len(linha) == 4:
                    try:
                        id_rota = int(linha[0])
                        nome, tipo, regiao = linha[1], linha[2], linha[3]

                        # Aplica o filtro se ele não estiver vazio
                        if not filtro or filtro.lower() in tipo.lower() or filtro.lower() in regiao.lower():
                            rotas_carregadas.append(Rota(id_rota, nome, tipo, regiao))
                    except ValueError:
                        print(f"Aviso: Ignorando linha com ID inválido: {linha}")
                    except IndexError:
                         print(f"Aviso: Ignorando linha mal formatada: {linha}")

    except FileNotFoundError:
        # Se o arquivo não existe, retorna lista vazia (primeira execução talvez)
        print(f"Aviso: Arquivo '{path_completo}' não encontrado. Nenhuma rota carregada.")
    except Exception as e:
        print(f"Erro inesperado ao ler o arquivo: {e}")

    return rotas_carregadas

def mostrar_rotas(lista_rotas: list[Rota]):
    """Imprime as rotas formatadas na lista fornecida."""
    if not lista_rotas:
        print("Nenhuma rota encontrada para o filtro fornecido.")
        return

    print("\n--- Rotas Encontradas ---")
    for rota in lista_rotas:
        print(rota)
    print("------------------------")


def adicionar_nova_rota(arquivo_path: str = NOME_ARQUIVO):
    """
    Solicita informações do usuário para uma nova rota e a adiciona ao arquivo CSV.
    """
    print("\n--- Adicionar Nova Rota ---")
    while True:
        try:
            id_rota = int(input("Digite o ID: "))
            break
        except ValueError:
            print("ID inválido. Por favor, digite um número.")

    nome = input("Digite o nome: ")
    tipo = input("Digite o tipo: ")
    regiao = input("Digite a região: ")

    nova_rota = Rota(id_rota, nome, tipo, regiao)

    try:
        # Garante que o diretório do script seja considerado se o path for relativo
        script_dir = os.path.dirname(__file__) if "__file__" in locals() else "."
        path_completo = os.path.join(script_dir, arquivo_path)

        # Cria o diretório se não existir
        os.makedirs(os.path.dirname(path_completo), exist_ok=True)


        # Verifica se o arquivo existe para adicionar cabeçalho se necessário (embora o original não tivesse)
        # existe = os.path.exists(path_completo)

        with open(path_completo, 'a', encoding='utf-8', newline='') as arquivo:
            escritor = csv.writer(arquivo, delimiter=';')
            # O arquivo original não tem cabeçalho, então não adicionamos um aqui.
            # if not existe:
            #     escritor.writerow(["ID", "Nome", "Tipo", "Regiao"]) # Exemplo se quisesse cabeçalho
            escritor.writerow([nova_rota.id, nova_rota.nome, nova_rota.tipo, nova_rota.regiao])
        print("Rota adicionada com sucesso!")

    except IOError as e:
        print(f"Erro ao escrever no arquivo '{path_completo}': {e}")
    except Exception as e:
        print(f"Erro inesperado ao adicionar rota: {e}") 