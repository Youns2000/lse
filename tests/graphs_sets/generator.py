import networkx as nx
from networkx.drawing.nx_agraph import write_dot, read_dot
from networkx.drawing.nx_agraph import graphviz_layout
from pygraphviz import *
import matplotlib.pyplot as plt
import random

# Gs = []
# Gs.append(nx.gnm_random_graph(100, 200, directed=False))
# Gs.append(nx.gnm_random_graph(100, 200, directed=False))
# Gs.append(nx.gnm_random_graph(100, 200, directed=False))
# Gs.append(nx.gnm_random_graph(100, 200, directed=True))
# Gs.append(nx.gnm_random_graph(100, 200, directed=True))

# i = 0
# for G in Gs:
#     for (u,v,w) in G.edges(data=True):
#         w['weight'] = random.randint(0,10)
#     write_dot(G, "./G"+str(i)+".dot")
#     i += 1

G = read_dot("./G0.dot")
print(nx.density(G))
print(nx.is_directed(G))
print(nx.number_of_nodes(G))
print(nx.number_of_edges(G))
print(nx.is_connected(G))
print(nx.diameter(G))
print(nx.average_shortest_path_length(G))
# print(nx.is_strongly_connected(G))
path = nx.all_pairs_shortest_path_length(G)
dpath = {x[0]:x[1] for x in path} 
# print(dpath['0']['93'])
# print(dpath['93']['0'])
# print(dpath['20']['11'])
# print(dpath['46']['11'])
# print(dpath['12']['13'])
# print(dpath['88']['0'])