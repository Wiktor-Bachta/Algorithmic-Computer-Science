import matplotlib.pyplot as plt
import networkx as nx

graphs = ["1/g4d.txt", "1/g4u.txt", "2/g2a-moj.txt", "2/g2b-moj.txt",
          "3/g3-moj1.txt", "3/g3-moj2.txt", "4/d4a-moj.txt", "4/d4b-moj.txt", "4/u4a-moj.txt", "4/u4b-moj.txt"]

for graph in graphs:
    with open("./aod_testy1/" + graph, "r") as input_file:
        directed = False
        if input_file.readline().strip() == "D":
            directed = True

        vertex_num = int(input_file.readline())
        edges = []

        edge = input_file.readline()  # skip edge count
        edge = input_file.readline()
        while edge:
            edges.append((int(edge.split(" ")[0]), int(edge.split(" ")[1])))
            edge = input_file.readline()

    if directed:
        G = nx.MultiDiGraph()
        G.add_edges_from(edges)
        plt.figure(figsize=(10, 8), dpi=150)
        try:
            nx.draw(G, with_labels=True, pos=nx.planar_layout(G))
        except nx.exception.NetworkXException:
            nx.draw(G, with_labels=True, pos=nx.kamada_kawai_layout(G))
        plt.savefig("./images/" + graph[2:-4] + ".jpg", bbox_inches='tight')
        plt.figure()
        # plt.show()
    else:
        G = nx.MultiGraph()
        G.add_edges_from(edges)
        plt.figure(figsize=(10, 8), dpi=150)

        try:
            nx.draw(G, with_labels=True, pos=nx.planar_layout(G))
        except nx.exception.NetworkXException:
            nx.draw(G, with_labels=True, pos=nx.kamada_kawai_layout(G))
        plt.savefig("./images/" + graph[2:-4] + ".jpg", bbox_inches='tight')
        plt.figure()
        # plt.show()
