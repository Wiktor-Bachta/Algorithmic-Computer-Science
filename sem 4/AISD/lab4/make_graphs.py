from os import listdir
import matplotlib.pyplot as plt
from csv import reader

def consecutive_lengths(lst):
    lengths = []
    current_length = 1

    for i in range(1, len(lst)):
        if lst[i] == lst[i - 1]:
            current_length += 1
        else:
            lengths.append(current_length)
            current_length = 1

    lengths.append(current_length)  
    return lengths

def make_graphs(files):
    for f in files:
        tree_name = f.split('/')[1]
        with open(f, 'r') as file:
            n = []
            cmp = []
            ptr = []
            h = []
            mcmp = []
            mptr = []
            mh = []
            csv_reader = reader(file)
            next(csv_reader)
            for row in csv_reader:
                n.append(float(row[0]))
                cmp.append(float(row[1]))
                ptr.append(float(row[2]))
                h.append(float(row[3]))
                mcmp.append(float(row[4]))
                mptr.append(float(row[5]))
                mh.append(float(row[6]))

            tmp_n = n
            n = []
            tmp_cmp = cmp
            cmp = []
            tmp_ptr = ptr
            ptr = []
            tmp_h = h
            h = []
            tmp_mcmp = mcmp
            mcmp = []
            tmp_mptr = mptr
            mptr = []
            tmp_mh = mh
            mh = []

            lengths = consecutive_lengths(tmp_n)
            for l in lengths:
                n.append(sum(tmp_n[:l])/l)
                tmp_n = tmp_n[l:]
                cmp.append(sum(tmp_cmp[:l])/l)
                tmp_cmp = tmp_cmp[l:]
                ptr.append(sum(tmp_ptr[:l])/l)
                tmp_ptr = tmp_ptr[l:]
                h.append(sum(tmp_h[:l])/l)
                tmp_h = tmp_h[l:]
                mcmp.append(sum(tmp_mcmp[:l])/l)
                tmp_mcmp = tmp_mcmp[l:]
                mptr.append(sum(tmp_mptr[:l])/l)
                tmp_mptr = tmp_mptr[l:]
                mh.append(sum(tmp_mh[:l])/l)
                tmp_mh = tmp_mh[l:]

            plt.subplot(2, 3, 1)
            plt.plot(n, cmp, label=tree_name)

            plt.subplot(2, 3, 2)
            plt.plot(n, ptr, label=tree_name)

            plt.subplot(2, 3, 3)
            plt.plot(n, h, label=tree_name)

            plt.subplot(2, 3, 4)
            plt.plot(n, mcmp, label=tree_name)

            plt.subplot(2, 3, 5)
            plt.plot(n, mptr, label=tree_name)

            plt.subplot(2, 3, 6)
            plt.plot(n, mh, label=tree_name)

    plt.subplot(2, 3, 1)
    plt.title('Comparisons')
    plt.legend()

    plt.subplot(2, 3, 2)
    plt.title('Pointer Changes')
    plt.legend()

    plt.subplot(2, 3, 3)
    plt.title('Height')
    plt.legend()

    plt.subplot(2, 3, 4)
    plt.title('Max Comparisons')
    plt.legend()

    plt.subplot(2, 3, 5)
    plt.title('Max Pointer Changes')
    plt.legend()

    plt.subplot(2, 3, 6)
    plt.title('Max Height')
    plt.legend()

    plt.tight_layout()
    plt.show()


if __name__ == '__main__':
    trees = listdir('data')

    increasing_files = []
    random_files = []

    for tree in trees:
        t = listdir('data/' + tree)
        increasing_files.append('data/' + tree + '/' + t[0])
        random_files.append('data/' + tree + '/' + t[1])

    make_graphs(increasing_files)
    make_graphs(random_files)
