#include <iostream>
#include <vector>

#include "edge.hh"

namespace gad
{
    template <typename T>
    class Node
    {
    public:
        Node(T* data);

        size_t get_id();
        std::vector<Edge> get_edges();
        std::vector<Node> get_adjency();

    private:
        long id_;
        T* data_;
        std::vector<Edge> edges_;
        std::vector<Node> adjacency_list_;  
        size_t degree_;
    };
}