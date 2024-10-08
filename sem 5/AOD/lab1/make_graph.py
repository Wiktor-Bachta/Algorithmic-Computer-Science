import matplotlib.pyplot as plt
import networkx as nx


with open("/home/wiktor/Desktop/AOD/lab1/tree.txt", "r") as input_file:
    vertex_num = int(input_file.readline())
    edges = []

    edge = input_file.readline() # skip first 1 1
    edge = input_file.readline()
    while edge:
        edges.append((int(edge.split(" ")[0]), int(edge.split(" ")[1])))
        edge = input_file.readline() 


# create a directed multi-graph
G = nx.MultiDiGraph()
G.add_edges_from(edges)
# plot the graph
nx.draw(G, with_labels=True, pos=nx.bfs_layout(G, 1))
plt.show()  # pause before exiting