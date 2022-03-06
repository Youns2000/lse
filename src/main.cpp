#include <iostream>
#include "graphslib/edge.hh"
#include "graphslib/graphs.hh"
#include "graphslib/graphs.cc"

using namespace std;

int main()
{
  Edge e('c', 'd', '7');

  // auto e = Edge<int>{1, 2, 3};
  Graph<int> g;
  g.add_edges({{1, 2, 3}, {0, 6, 1}, {2, 3, 1}});
  g.add_edges({{1, 2, 90}});

  cout << g << g.get_nb_nodes() << "\n" << g.get_nb_edges() << endl;

  return 0;
}