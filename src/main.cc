#include "gad/gad.hh"

using namespace std;

int main()
{
    auto rand_adj = random_graph_generator(10, 20, 1, 5, true);
    auto rand_adj_2 = random_graph_generator(100, 200, 1, 5, false);
    auto rand_adj_3 = random_graph_generator(10, 5, 1, 5, false);

    write_dot("tests/graphs_sets/random_graph", rand_adj, true);
    write_dot("tests/graphs_sets/random_graph_2", rand_adj_2, false);
    write_dot("tests/graphs_sets/random_graph_3", rand_adj_3, false);

    convert_to_png("tests/graphs_sets/random_graph");
    convert_to_png("tests/graphs_sets/random_graph_2");
    convert_to_png("tests/graphs_sets/random_graph_3");

    return 0;
}