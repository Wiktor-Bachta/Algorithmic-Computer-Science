from os import listdir
import matplotlib.pyplot as plt
from csv import reader

files = listdir('../data/low')

for f in files:
    with open('../data/low/' + f, 'r') as file:
        n = []
        c = []
        s = []
        c_n = []
        s_n = []

        csv_reader = reader(file)
        next(csv_reader)
        for row in csv_reader:
            n.append(int(row[0]))
            c.append(float(row[1]))
            s.append(float(row[2]))
            c_n.append(float(row[3]))
            s_n.append(float(row[4]))

        plt.subplot(2, 2, 1)
        plt.plot(n, c, label=f[:-4])

        plt.subplot(2, 2, 2)
        plt.plot(n, s, label=f[:-4])

        plt.subplot(2, 2, 3)
        plt.plot(n, c_n, label=f[:-4])

        plt.subplot(2, 2, 4)
        plt.plot(n, s_n, label=f[:-4])

plt.subplot(2, 2, 1)
plt.legend()
plt.xlabel('n')
plt.ylabel('c')

plt.subplot(2, 2, 2)
plt.legend()
plt.xlabel('n')
plt.ylabel('s')

plt.subplot(2, 2, 3)
plt.legend()
plt.xlabel('n')
plt.ylabel('c/n')

plt.subplot(2, 2, 4)
plt.legend()
plt.xlabel('n')
plt.ylabel('s/n')

plt.tight_layout()

plt.show()
