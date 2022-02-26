#include <iostream>
#include <array>

#include "node.hh"
#include "edge.hh"

namespace gad
{
    template <typename T>
    class Graph
    {
    public:
        Graph add_node(T* data);
        Graph remove_node(long id_);
        Node find_node();
        Edge find_edge();

        std::array<std::array<int, nb_nodes>, nb_nodes> graph_to_adj_matrix();

        size_t get_nb_nodes();
        bool is_connected();

    private:
        size_t nb_nodes;
        bool connected;
    };
}