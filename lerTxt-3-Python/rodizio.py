import csv
import os

NOME_ARQUIVO = "rodizio_de_veiculos.txt"

class Veiculo:
    def __init__(self, placa: str, dia_semana: str, horario: str):
        self.placa = placa
        self.dia_semana = dia_semana
        self.horario = horario

    def __str__(self):
        return f"Placa: {self.placa}\nDia: {self.dia_semana}\nHorário: {self.horario}\n"

def carregar_veiculos(criterio_dia: str, arquivo_path: str = NOME_ARQUIVO) -> list[Veiculo]:
    veiculos_carregados = []
    try:
        script_dir = os.path.dirname(__file__) if "__file__" in locals() else "."
        path_completo = os.path.join(script_dir, arquivo_path)
        os.makedirs(os.path.dirname(path_completo), exist_ok=True)

        with open(path_completo, 'r', encoding='utf-8', newline='') as arquivo:
            leitor = csv.reader(arquivo, delimiter=';')
            for linha in leitor:
                if len(linha) == 3:
                    placa, dia, horario = linha[0], linha[1], linha[2]
                    if criterio_dia.strip().lower() == dia.strip().lower():
                        veiculos_carregados.append(Veiculo(placa, dia, horario))
                else:
                     print(f"Aviso: Ignorando linha mal formatada: {linha}")

    except FileNotFoundError:
        print(f"Aviso: Arquivo '{path_completo}' não encontrado. Certifique-se de que ele existe no mesmo diretório do script.")
    except Exception as e:
        print(f"Erro inesperado ao carregar veículos: {e}")

    return veiculos_carregados

def exibir_veiculos(lista_veiculos: list[Veiculo]):
    if not lista_veiculos:
        print("Nenhum veículo encontrado para este dia da semana.")
        return

    print("\n--- Veículos Encontrados ---")
    for veiculo in lista_veiculos:
        print(veiculo)
    print("--------------------------")