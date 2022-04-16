import networkx as nx
from networkx.drawing.nx_agraph import write_dot, read_dot
from networkx.drawing.nx_agraph import graphviz_layout
from pygraphviz import *
import matplotlib.pyplot as plt
import random

fig = plt.figure(figsize=(12,12))
ax = plt.subplot(111)
# ax.set_title('Graph - Shapes', fontsize=10)

G = nx.gnm_random_graph(10, 20, directed=False)
# G.add_node()
# G.add_node()
# G.add_node()
# G.add_node()
# G.add_node()
pos = nx.spring_layout(G)
nx.draw(G, pos, node_size=3000, font_weight='bold')

plt.tight_layout()
# plt.show()
plt.savefig("Graph.png", format="PNG")

write_dot(G, "G1.dot")

# G = nx.gnm_random_graph(100, 300, directed=True)
# for (u,v,w) in G.edges(data=True):
#     w['weight'] = random.randint(0,10)
# write_dot(G, "./random_weighted_graph.dot")

# G = read_dot("./random_graph.dot")
# print(nx.density(G))
# print(nx.is_directed(G))
# print(nx.number_of_nodes(G))
# print(nx.number_of_edges(G))
# path = nx.all_pairs_shortest_path_length(G)
# dpath = {x[0]:x[1] for x in path} 
# print(dpath['0']['93'])
# print(dpath['93']['0'])
# print(dpath['20']['11'])
# print(dpath['46']['11'])
# print(dpath['99']['1'])
# print(dpath['12']['13'])
# print(dpath['88']['0'])