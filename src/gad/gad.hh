#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <graphviz/gvc.h>

using namespace std;

// https://www.simplilearn.com/tutorials/data-structure-tutorial/graphs-in-data-structure
enum graph_type
{
    SIMPLE,
    REGULAR,
    CYCLIC,
    COMPLETE,
    QUASI_COMPLETE,
    INTERMEDIARY,
    SPARSE
};

int get_nb_nodes(vector<vector<pair<int, float>>> adj_list);
int get_nb_edges(vector<vector<pair<int, float>>> adj_list, bool is_directed);

bool is_connected(vector<vector<pair<int, float>>> adj_list);
bool is_edge_connected(vector<vector<pair<int, float>>> adj_list, bool is_directed);

// GRAPHS CONVERTERS
vector<vector<pair<int, float>>> from_edges_to_adj_list(vector<tuple<int, float, int>> edges, bool is_directed);
vector<tuple<int, float, int>> from_adj_list_to_edges(vector<vector<pair<int, float>>> adj_list);
vector<vector<int>> from_adj_list_to_adj_matrix(vector<vector<pair<int, float>>> adj_list, bool is_directed);
pair<vector<vector<pair<int, float>>>, bool> read_dot(string file_path);
void write_dot(const string filename, vector<vector<pair<int, float>>> adj_list, bool is_directed);




// GRAPHS METRICS
float get_average_degree(vector<vector<pair<int, float>>> adj_list);
float get_average_weighted_degree(vector<vector<pair<int, float>>> adj_list);
int get_distance(vector<vector<pair<int, float>>>& adj_list, int start, int target);
int get_diameter(vector<vector<pair<int, float>>> adj_list);
float get_average_path_length(vector<vector<pair<int, float>>> adj_list);
float get_density(vector<vector<pair<int, float>>> adj_list, bool is_directed);
float get_modularity(vector<vector<pair<int, float>>> adj_list, bool is_directed);
int get_eccentricity(vector<vector<pair<int, float>>> adj_list, bool is_directed);

// GRAPHS GENERATORS
vector<vector<pair<int, float>>> random_graph_generator(int nb_vertices, int nb_edges, unsigned seed, int weights_seed, bool is_directed);
vector<vector<pair<int, float>>> complete_graph_generator(int nb_vertices, unsigned seed, int weights_seed);

// DISPLAY
bool convert_to_png(string file_path);
void print_graph_props(vector<vector<pair<int, float>>> adj_list, bool is_directed, string name);
void print_adj_list(vector<vector<pair<int, float>>> adj_list);