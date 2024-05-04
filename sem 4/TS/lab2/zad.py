import graph_parameters as gp
import igraph as ig
import random
import numpy as np


def is_connected(g):
    for edge in g.es:
        if random.random() > edge["reliability"]:
            g.delete_edges(edge)
    return g.is_connected()


def capacity_ok(g, flow, N):
    for i in range(len(g.vs)):
        for j in range(i+1, len(g.vs)):
            path = g.get_shortest_paths(i, to=j)[0]
            for k in range(len(path) - 1):
                edge = g.es[g.get_eid(path[k], path[k+1])]
                flow[edge] += N[i][j] + N[j][i]
    for edge in g.es:
        if flow[edge] > edge["capacity"] / gp.packet_size:
            return False
    return True


def delay_ok(g, flow, N):
    delay = 0
    for edge in g.es:
        delay += flow[edge] / (edge["capacity"] / gp.packet_size - flow[edge])
    delay /= np.sum(N)
    return delay < gp.max_delay


def simulate(g, N=gp.N):
    if not is_connected(g):
        return False
    flow = {egde: 0 for egde in g.es}
    if not capacity_ok(g, flow, N):
        return False
    if not delay_ok(g, flow, N):
        return False
    return True


def main():
    tries = 1000

    #zwykły test
    successes = 0
    for _ in range(tries):
        G = gp.g.copy()
        if simulate(G):
            successes += 1
    print(f"Niezawodność sieci: {successes/tries * 100:.2f}%")

    #test ze zwiększaniem N
    for i in range(1, 6):
        successes = 0
        mult = 1 + i/10
        new_N = [[j * mult for j in row] for row in gp.N]
        for _ in range(tries):
            G = gp.g.copy()
            if simulate(G, new_N):
                successes += 1
        print(
            f"Niezawodność sieci dla wartości w N pomnożonych przez {mult}: {successes/tries * 100:.2f}%")

    #test ze zwiększaniem przepustowości
    for i in range(1, 6):
        successes = 0
        mult = 1 + i/5
        new_g = gp.g.copy()
        new_g.es["capacity"] = [c * mult for c in new_g.es["capacity"]]
        for _ in range(tries):
            G = new_g.copy()
            if simulate(G):
                successes += 1
        print(
            f"Niezawodność sieci dla przepustowości przez {mult}: {successes/tries * 100:.2f}%")
    

    #test z dodawanymi krawędziami
    avg_capacity = np.mean(gp.g.es["capacity"])
    avg_reliability = np.mean(gp.g.es["reliability"])
    new_g = gp.g.copy()
    to_add = 2
    a, b = new_g.es[0].source, new_g.es[0].target

    for i in range(1, 6):
        successes = 0
        for _ in range(to_add):
            while (a, b) in new_g.get_edgelist():
                a, b = random.randint(
                    0, len(new_g.vs)-2), random.randint(a + 1, len(new_g.vs)-1)

            new_g.add_edge(
                a,
                b,
                capacity=avg_capacity,
                reliability=avg_reliability
            )

        for _ in range(tries):
            G = new_g.copy()
            if simulate(G):
                successes += 1
        print(
            f"Niezawodność sieci dla {i * to_add} dodanych krawędzi: {successes/tries * 100:.2f}%")


if __name__ == "__main__":
    main()
