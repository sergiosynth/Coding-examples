import time
import os
import re

def parse_tiempo(tiempo_str):
    try:
        horas, minutos, segundos = map(int, re.split(r"[:]", tiempo_str))
        return horas * 3600 + minutos * 60 + segundos
    except ValueError:
        print("Formato incorrecto. Ingresa el tiempo en formato HH:MM:SS.")
        return None

def countdown():
    tiempo_str = input("Ingresa el tiempo inicial en formato HH:MM:SS: ")
    tiempo_inicial = parse_tiempo(tiempo_str)
    
    if tiempo_inicial is None:
        return

    while tiempo_inicial > 0:
        tiempo_restante = time.strftime("%H:%M:%S", time.gmtime(tiempo_inicial))
        os.system("cls" if os.name == "nt" else "clear")  # Limpia la pantalla
        print(f"\033[1;31mTiempo restante: {tiempo_restante}\033[0m")
        tiempo_inicial -= 1
        time.sleep(1)

    print("\033[1;31m¡LISTO MEN!\033[0m")

countdown()
