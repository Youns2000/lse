#include <iostream>
#include "graphslib/edge.hh"
#include "graphslib/graphs.hh"
#include "graphslib/graphs.cc"

using namespace std;

int main()
{
  Graph<int> g;
    g.add_edges({{1, 2, 3}, {0, 6, 1}, {2, 3, 1}, {1, 2, 90}});

    vector<vector<pair<int, int>>> expected_adj_list = 
    {
        {make_pair(1, 6)},
        {make_pair(3, 2), make_pair(90, 2)},
        {make_pair(1, 3)}
    };

    vector<vector<pair<int, int>>> adj_list = g.convert_to_adjancy_list();

  return 0;
}