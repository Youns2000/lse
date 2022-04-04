#include "gad/gad.hh"

using namespace std;

int main()
{
    std::vector<std::vector<std::pair<int, float>>> adj =
    {
        {
            make_pair(1, 6.),
            make_pair(2, 6.)
        },
        {
            make_pair(3, 6.),
            make_pair(2, 6.)
        },
        {
            make_pair(5, 6.),
            make_pair(6, 6.)
        },
        {
            make_pair(7, 6.),
            make_pair(8, 6.),
            make_pair(1, 6.)
        },
        {
            make_pair(4, 6.)
        }
    };

    std::vector<std::vector<std::pair<int, float>>> rand_adj = random_graph_generator(20, 200, 1, 5);
    std::vector<std::vector<std::pair<int, float>>> complete_graph = complete_graph_generator(6, 1, 5);

    graph_print_params(adj, false, "Basic");
    graph_print_params(rand_adj, false, "rand_adj");
    graph_print_params(complete_graph, false, "complete_graph");

    return 0;
}
