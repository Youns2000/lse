#pragma once

#include <iostream>
#include <vector>
#include <optional>

#include "edge.hh"

using namespace std;

template <typename T>
class Graph
{
public:
    Graph() = default;
    Graph<T> add_edges(std::vector<Edge<T>> edges);
    int get_nb_nodes();
    int get_nb_edges();
    bool is_connected();
    vector<vector<pair<T, T>>> convert_to_adjancy_list();

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Graph<U>& g)
    {
        for (auto& e : g.edges_)
            os << e << "\n";
        return os;
    }

    std::vector<Edge<T>> edges_;
};
