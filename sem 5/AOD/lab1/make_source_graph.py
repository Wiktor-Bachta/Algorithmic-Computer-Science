import matplotlib.pyplot as plt
import networkx as nx


with open("/home/wiktor/Desktop/AOD/lab1/aod_testy1/2/g2a-1.txt", "r") as input_file:
    directed = False
    if input_file.readline().strip() == "D":
        directed = True

    vertex_num = int(input_file.readline())
    edges = []

    edge = input_file.readline() # skip edge count
    edge = input_file.readline()
    while edge:
        edges.append((int(edge.split(" ")[0]), int(edge.split(" ")[1])))
        edge = input_file.readline() 

if directed:
    G = nx.MultiDiGraph()
    G.add_edges_from(edges)
    nx.draw(G, with_labels=True, pos=nx.planar_layout(G))
    plt.show()  
else:
    G = nx.MultiGraph()
    G.add_edges_from(edges)
    nx.draw(G, with_labels=True, pos=nx.planar_layout(G))
    plt.show() 