#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <graphviz/gvc.h>

template <class T>
int get_nb_nodes(std::vector<std::vector<std::pair<T, float>>> adj_list);

template <class T>
int get_nb_edges(std::vector<std::vector<std::pair<T, float>>> adj_list, bool is_directed);

template <class T>
bool is_connected(std::vector<std::vector<std::pair<T, float>>> adj_list);

template <class T>
bool is_edge_connected(std::vector<std::vector<std::pair<T, float>>> adj_list);

template <class T>
std::vector<std::vector<std::pair<T, float>>> from_edges_to_adj_list(std::vector<std::tuple<T, float, T>> edges, bool is_directed);

template <class T>
std::vector<std::tuple<T, float, T>> from_adj_list_to_edges(std::vector<std::vector<std::pair<T, float>>> adj_list, bool is_directed);

template <class T>
int get_average_degree(std::vector<std::vector<std::pair<T, float>>> adj_list);

template <class T>
int get_average_weighted_degree(std::vector<std::vector<std::pair<T, float>>> adj_list);

template <class T>
int get_average_path_length(std::vector<std::vector<std::pair<T, float>>> adj_list);

template <class T>
float get_density(std::vector<std::vector<std::pair<T, float>>> adj_list);

template <class T>
float get_modularity(std::vector<std::vector<std::pair<T, float>>> adj_list);

// template <class T>
std::vector<std::vector<std::pair<int, float>>> int_graph_generator(int nb_vertices, int nb_edges, unsigned seed, int weights_seed);

template <class T>
void graphs_save(std::string filename, std::vector<std::vector<std::pair<T, float>>> adj_list, bool is_directed);

bool convert_to_png(std::string file_path);