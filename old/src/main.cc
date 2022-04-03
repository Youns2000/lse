#include "graphslib/graphs.hh"
#include "graphslib/graphs.cc"

using namespace std;

int main()
{
    // std::vector<std::vector<std::pair<int, float>>> adj_l = int_graph_generator(100, 70, 1, 5, "test_graph", false);
    // // graphs_save("test_graph", adj_l, false);
    // convert_to_png("test_graph");
    // std::cout << get_modularity(adj_l);

    Graph<int> g(
        false,
        {
            {
                make_pair(1, 6.),
                make_pair(2, 6.)
            },
            {
                make_pair(3, 6.),
                make_pair(4, 6.)
            },
            {
                make_pair(5, 6.),
                make_pair(6, 6.)
            },
            {
                make_pair(7, 6.),
                make_pair(8, 6.)
            }
        }
    );

    cout << g.is_directed_ << endl 
        << g.get_nb_edges() << endl
        << g.get_nb_nodes() << endl;

    g.graphs_save("graph");

    return 0;
}