#include "gad/gad.hh"

using namespace std;

int main()
{
    std::vector<std::vector<std::pair<int, float>>> adj =
    {
        {make_pair(0, 1.), make_pair(1, 1.), make_pair(3, 1.)},
        {make_pair(2, 1.), make_pair(1, 1.), make_pair(0, 1.)},
        {make_pair(4, 1.), make_pair(5, 1.), make_pair(1, 1.)},
        {make_pair(6, 1.), make_pair(7, 1.), make_pair(0, 1.)},
        {make_pair(2, 1.)},
        {make_pair(2, 1.)},
        {make_pair(3, 1.)},
        {make_pair(3, 1.)}
    };

    // std::vector<std::vector<std::pair<int, float>>> rand_adj = random_graph_generator(10, 100, 1, 5);
    // std::vector<std::vector<std::pair<int, float>>> complete_graph = complete_graph_generator(8, 1, 5);

    // print_graph_props(adj, false, "Basic");
    // cout << get_distance(adj, 3, 7) << endl;
    // cout << get_distance(adj, 3, 5) << endl;
    // print_graph_props(complete_graph, false, "complete_graph");
    // print_graph_props(rand_adj, false, "rand_adj");
    // convert_to_png("tests/graphs_sets/random_graph");
    read_dot("tests/graphs_sets/random_weighted_graph.dot");

    return 0;
}