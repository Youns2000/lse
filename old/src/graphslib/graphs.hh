#pragma once

#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <graphviz/gvc.h>

template <typename T>
class Graph
{
public:
    Graph(bool is_directed, std::vector<std::vector<std::pair<T, float>>> adj_list)
    : is_directed_(is_directed)
    , adj_list_(adj_list)
    {}
    // Graph<T> add_edges(std::vector<Edge<T>> edges);

    int get_nb_nodes();
    int get_nb_edges();
    bool is_connected();
    bool is_edge_connected();

    // void from_edges_to_adj_list();
    std::vector<std::tuple<T, float, T>> from_adj_list_to_edges();

    int get_average_degree();
    int get_average_weighted_degree();
    int get_average_path_length();

    float get_density();
    float get_modularity();
    int connected_components();
    
    std::vector<std::vector<std::pair<int, float>>> int_graph_generator(int nb_vertices, int nb_edges, unsigned seed, int weights_seed);
    void graphs_save(const std::string filename);
    bool convert_to_png(const std::string filename);
    
    // int eccentricity(T* node);

    // template <typename U>
    // friend std::ostream& operator<<(std::ostream& os, const Graph<U>& g)
    // {
    //     for (auto& e : g.edges_)
    //         os << e << "\n";
    //     return os;
    // }

    bool is_directed_;
    std::vector<std::vector<std::pair<T, float>>> adj_list_;
};

// enum graph_type
// {
//     COMPLETE,
//     QUASI_COMPLETE,
//     INTERMEDIARY,
//     SPARSE
// };

// template <class T>
// int get_nb_nodes(std::vector<std::vector<std::pair<T, float>>> adj_list);

// template <class T>
// int get_nb_edges(std::vector<std::vector<std::pair<T, float>>> adj_list, bool is_directed);

// template <class T>
// bool is_connected(std::vector<std::vector<std::pair<T, float>>> adj_list);

// template <class T>
// bool is_edge_connected(std::vector<std::vector<std::pair<T, float>>> adj_list);

// template <class T>
// std::vector<std::vector<std::pair<T, float>>> from_edges_to_adj_list(std::vector<std::tuple<T, float, T>> edges, bool is_directed);

// template <class T>
// std::vector<std::tuple<T, float, T>> from_adj_list_to_edges(std::vector<std::vector<std::pair<T, float>>> adj_list, bool is_directed);

// template <class T>
// int get_average_degree(std::vector<std::vector<std::pair<T, float>>> adj_list);

// template <class T>
// int get_average_weighted_degree(std::vector<std::vector<std::pair<T, float>>> adj_list);

// template <class T>
// int get_average_path_length(std::vector<std::vector<std::pair<T, float>>> adj_list);

// template <class T>
// float get_density(std::vector<std::vector<std::pair<T, float>>> adj_list);

// template <typename T>
// float get_modularity(T adj_list);
// // float get_modularity(const std::vector<std::vector<std::pair<T, float>>>& adj_list);

// // template <class T>
// std::vector<std::vector<std::pair<int, float>>> int_graph_generator(int nb_vertices, int nb_edges, unsigned seed, int weights_seed, const std::string filename, bool is_directed);

// // template <class T>
// // void graphs_save(const std::string filename, std::vector<std::vector<std::pair<T, float>>> adj_list, bool is_directed);

// bool convert_to_png(std::string file_path);