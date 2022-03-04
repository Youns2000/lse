#pragma once

#include <iostream>
#include <vector>
#include <optional>

#include "edge.hh"

template <typename T>
class Graph
{
public:
    // Graph(std::optional<std::vector<Edge>> edges) : edges_(edges) {}
    Graph() = default;
    Graph<T> add_edges(std::vector<Edge<T>> edges);
    int get_nb_nodes();
    int get_nb_edges();
    bool is_connected();

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Graph<U>& g)
    {
        for (auto& e : g.edges_)
            os << e << "\n";
        return os;
    }

    std::vector<Edge<T>> edges_;
};
