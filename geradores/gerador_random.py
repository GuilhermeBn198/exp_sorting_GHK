import csv
import random

lista = ','.join(map(str, [random.randint(0, 101) for i in range(101)]))
with open("lista_randomica.csv", "w", newline="") as file:
    writer = csv.writer(file)
    writer.writerow(lista.split(" "))
