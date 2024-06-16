from os import listdir
import matplotlib.pyplot as plt
from csv import reader

with open('data/times.txt', 'r') as file:
    n = []
    prim = []
    kruskal = []

    csv_reader = reader(file)
    next(csv_reader)

    for row in csv_reader:
        n.append(int(row[0]))
        prim.append(float(row[1]))
        kruskal.append(float(row[2]))

plt.plot(n, prim, label="Prim")
plt.plot(n, kruskal, label="Kruskal")

plt.title("MST generation time")
plt.legend()
plt.xlabel('n')
plt.ylabel('time[nano]')

plt.show()
