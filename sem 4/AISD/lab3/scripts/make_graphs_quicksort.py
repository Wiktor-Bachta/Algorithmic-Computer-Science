from os import listdir
import matplotlib.pyplot as plt
from csv import reader

modes = ["-i", "-d", "-n"]

for mode in modes:

    files = listdir('../data/quicksort/' + mode)

    for f in files:
        with open('../data/quicksort/' + mode + "/" + f, 'r') as file:
            n = []
            c = []
            s = []
            c_n = []
            s_n = []
            c_nn = []
            s_nn = []

            csv_reader = reader(file)
            next(csv_reader)
            for row in csv_reader:
                n.append(int(row[0]))
                c.append(float(row[1]))
                s.append(float(row[2]))
                c_n.append(float(row[3]))
                s_n.append(float(row[4]))
                c_nn.append(float(row[5]))
                s_nn.append(float(row[6]))

            plt.subplot(2, 3, 1)
            plt.plot(n, c, label=f[:-4])

            plt.subplot(2, 3, 4)
            plt.plot(n, s, label=f[:-4])

            plt.subplot(2, 3, 2)
            plt.plot(n, c_n, label=f[:-4])

            plt.subplot(2, 3, 5)
            plt.plot(n, s_n, label=f[:-4])

            plt.subplot(2, 3, 3)
            plt.plot(n, c_nn, label=f[:-4])

            plt.subplot(2, 3, 6)
            plt.plot(n, s_nn, label=f[:-4])

    plt.subplot(2, 3, 1)
    plt.legend()
    plt.xlabel('n')
    plt.ylabel('c')

    plt.subplot(2, 3, 4)
    plt.legend()
    plt.xlabel('n')
    plt.ylabel('s')

    plt.subplot(2, 3, 2)
    plt.legend()
    plt.xlabel('n')
    plt.ylabel('c/(n*ln(n))')

    plt.subplot(2, 3, 5)
    plt.legend()
    plt.xlabel('n')
    plt.ylabel('s/(n*ln(n))')

    plt.subplot(2, 3, 3)
    plt.legend()
    plt.xlabel('n')
    plt.ylabel('c/(n*n)')

    plt.subplot(2, 3, 6)
    plt.legend()
    plt.xlabel('n')
    plt.ylabel('s/(n*n)')

    plt.tight_layout()

    plt.show()
