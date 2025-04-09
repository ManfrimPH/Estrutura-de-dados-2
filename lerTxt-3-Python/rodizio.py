class Rodizio:
    def __init__(self, placa: str, dia_semana: str, horario: str):
        self.placa = placa
        self.dia_semana = dia_semana
        self.horario = horario

    def imprimir(self):
        print(f"Placa: {self.placa} | Dia: {self.dia_semana} | Horário: {self.horario}")