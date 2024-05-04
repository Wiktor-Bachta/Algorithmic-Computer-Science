from os import listdir
import matplotlib.pyplot as plt
from csv import reader

files = listdir('../data/binary')

for f in files:
    with open('../data/binary/' + f, 'r') as file:
        n = []
        c = []
        time = []
        c_ln_n = []

        csv_reader = reader(file)
        next(csv_reader)
        for row in csv_reader:
            n.append(int(row[0]))
            c.append(float(row[1]))
            time.append(float(row[2]))
            c_ln_n.append(float(row[3]))

        plt.subplot(2, 2, 1)
        plt.plot(n, c, label=f[:-4])

        plt.subplot(2, 2, 2)
        plt.plot(n, time, label=f[:-4])

        plt.subplot(2, 2, 3)
        plt.plot(n, c_ln_n, label=f[:-4])

plt.subplot(2, 2, 1)
plt.legend()
plt.xlabel('n')
plt.ylabel('c')

plt.subplot(2, 2, 2)
plt.legend()
plt.xlabel('n')
plt.ylabel('time')

plt.subplot(2, 2, 3)
plt.legend()
plt.xlabel('n')
plt.ylabel('c/ln(n)')

plt.tight_layout()

plt.show()
