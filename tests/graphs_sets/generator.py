import networkx as nx
from networkx.drawing.nx_agraph import write_dot, read_dot
from networkx.drawing.nx_agraph import graphviz_layout
from pygraphviz import *
import matplotlib.pyplot as plt
import random
import numpy as np

# Gs = []
# Gs.append(nx.gnm_random_graph(100, 200, directed=False))
# Gs.append(nx.gnm_random_graph(100, 200, directed=False))
# Gs.append(nx.gnm_random_graph(100, 200, directed=False))
# Gs.append(nx.gnm_random_graph(100, 200, directed=True))
# Gs.append(nx.gnm_random_graph(100, 200, directed=True))


for i in range(5):
    # G = nx.gnm_random_graph(100, 300, directed=bool(random.getrandbits(1)))
    # for (u,v,w) in G.edges(data=True):
    #     w['weight'] = random.randint(0,10)
    # write_dot(G, "./G"+str(i)+".dot")

    

    name = "G"+str(i)
    path = "./"+name+".dot"
    path_conf = "./"+name+".graph"
    f = open(path_conf, "a")
    G = read_dot(path)
    print(path)
    print(name)

    print("nb nodes: " + str(nx.number_of_nodes(G)))
    f.write(str(nx.number_of_nodes(G)) + "\n")

    print("nb edges: " + str(nx.number_of_edges(G)))
    f.write(str(nx.number_of_edges(G))+ "\n")

    print("directed: " + str(nx.is_directed(G)))
    f.write(str(nx.is_directed(G))+ "\n")
    co = False
    if (not nx.is_directed(G) and nx.is_connected(G)) or (nx.is_directed(G) and nx.is_strongly_connected(G)):
        co = True
    print("connected: " + str(co))
    f.write(str(co)+ "\n")
    avg_w_deg = sum(n for _, n in G.degree(list(G.nodes))) / len(list(G.nodes))
    print("average_degree: " + str(avg_w_deg))
    f.write(str(avg_w_deg)+ "\n")

    # print(G.degree(weight='weight'))
    # print("average weighted degree: " + str(sum(n for _, n in G.degree(weight='weight')) / len(list(G.nodes))))
    # print("average weighted degree: " + str(0))
    if co:
        print("diameter: " + str(nx.diameter(G)))
        f.write(str(nx.diameter(G))+ "\n")
        print("average_path_length_: " + str(nx.average_shortest_path_length(G)))
        f.write(str(nx.average_shortest_path_length(G))+ "\n")
        print("density: " + str(nx.density(G)))
        f.write(str(nx.density(G))+ "\n")
    else:
        f.write(str(0)+ "\n" + str(0)+ "\n" + str(0)+ "\n")
        # print("modularity: " + str(nx.modularity(G)))
    path = nx.all_pairs_shortest_path_length(G)
    dpath = {x[0]:x[1] for x in path} 
    print(dpath['0']['93'])
    # print(dpath['93']['2'])
    print(dpath['20']['11'])
    print(dpath['46']['11'])
    print(dpath['12']['13'])
    print(dpath['88']['0'])
    f.close()

# name = "G0"
# path = "./"+name+".dot"
# # G = read_dot(path)
# print(path)
# print(name)
# print("nb nodes: " + str(nx.number_of_nodes(G)))
# print("nb edges: " + str(nx.number_of_edges(G)))
# print("directed: " + str(nx.is_directed(G)))
# print("connected: " + str(nx.is_connected(G)))
# print("average_degree: " + str(sum(n for _, n in G.degree(list(G.nodes))) / len(list(G.nodes))))
# print("diameter: " + str(nx.diameter(G)))
# print("density: " + str(nx.average_shortest_path_length(G)))
# print("modularity: " + str((nx.density(G))))

