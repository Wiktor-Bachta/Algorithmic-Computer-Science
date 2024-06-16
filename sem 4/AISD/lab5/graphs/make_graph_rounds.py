from os import listdir
import matplotlib.pyplot as plt
from csv import reader

with open('data/rounds.txt', 'r') as file:
    n = []
    min = []
    max = []
    avg = []

    csv_reader = reader(file)
    next(csv_reader)

    for row in csv_reader:
        n.append(int(row[0]))
        min.append(float(row[1]))
        max.append(float(row[2]))
        avg.append(float(row[3]))

plt.plot(n, min, label="minimum")
plt.plot(n, max, label="maximum")
plt.plot(n, avg, label="average")

plt.title("MST propagation in rounds")
plt.legend()
plt.xlabel('n')
plt.ylabel('rounds')

plt.show()
