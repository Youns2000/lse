#pragma once

#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphviz/gvc.h>

enum graph_type
{
    COMPLETE,
    QUASI_COMPLETE,
    INTERMEDIARY,
    SPARSE
};

// def is_connected(n, edges):
//     if n == 0:
//         return True
//     # Convert to adjacency list
//     succ = [[] for a in range(n)]
//     for (a,b) in edges:
//         succ[a].append(b)
//         succ[b].append(a)
//     # DFS over the graph
//     touched = [False] * n
//     touched[0] = True
//     todo = [0]
//     while todo:
//         s = todo.pop()
//         for d in succ[s]:
//             if not touched[d]:
//                 touched[d] = True
//                 todo.append(d)
//     return sum(touched) == n

void graph_print_params(std::vector<std::vector<std::pair<int, float>>> adj_list, bool is_directed, std::string name);

int get_nb_nodes(std::vector<std::vector<std::pair<int, float>>> adj_list);
int get_nb_edges(std::vector<std::vector<std::pair<int, float>>> adj_list, bool is_directed);

bool is_connected(std::vector<std::vector<std::pair<int, float>>> adj_list);
bool is_edge_connected(std::vector<std::vector<std::pair<int, float>>> adj_list);

// GRAPHS CONVERTERS
std::vector<std::vector<std::pair<int, float>>> from_edges_to_adj_list(std::vector<std::tuple<int, float, int>> edges, bool is_directed);
std::vector<std::tuple<int, float, int>> from_adj_list_to_edges(std::vector<std::vector<std::pair<int, float>>> adj_list, bool is_directed);
std::vector<std::vector<int>> from_adj_list_to_adj_matrix(std::vector<std::vector<std::pair<int, float>>> adj_list, bool is_directed);

// GRAPHS METRICS
float get_average_degree(std::vector<std::vector<std::pair<int, float>>> adj_list);
float get_average_weighted_degree(std::vector<std::vector<std::pair<int, float>>> adj_list);
int get_average_path_length(std::vector<std::vector<std::pair<int, float>>> adj_list);
int get_diameter(std::vector<std::vector<std::pair<int, float>>> adj_list);
float get_density(std::vector<std::vector<std::pair<int, float>>> adj_list);
float get_modularity(const std::vector<std::vector<std::pair<int, float>>> adj_list);

// GRAPHS GENERATORS
std::vector<std::vector<std::pair<int, float>>> random_graph_generator(int nb_vertices, int nb_edges, unsigned seed, int weights_seed);
std::vector<std::vector<std::pair<int, float>>> complete_graph_generator(int nb_vertices, unsigned seed, int weights_seed);

// GRAPHS SAVE & DISPLAY
void graphs_save(const std::string filename, std::vector<std::vector<std::pair<int, float>>> adj_list, bool is_directed);
bool convert_to_png(std::string file_path);