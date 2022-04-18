#include "../src/gad/gad.hh"
#include <gtest/gtest.h>
#include "graph_test.hh"

using namespace std;

GraphTest g0 = props_reader("./tests/graphs_sets/G0.graph", "G0");

auto adj = read_dot("./tests/graphs_sets/G0.dot");
TEST(g0, get_nb_nodes)
{
    EXPECT_EQ(g0.nb_nodes_, get_nb_nodes(get<0>(adj)));
}
TEST(g0, get_nb_edges)
{
    EXPECT_EQ(g0.nb_edges_, get_nb_edges(get<0>(adj), get<1>(adj)));
}
TEST(g0, is_connected)
{
    EXPECT_EQ(g0.is_connected_, is_connected(get<0>(adj)));
}
TEST(g0, get_average_degree)
{
    EXPECT_EQ(g0.average_degree_, get_average_degree(get<0>(adj), get<1>(adj)));
}
TEST(g0, get_average_weighted_degree)
{
    EXPECT_EQ(g0.average_weighted_degree_, get_average_weighted_degree(get<0>(adj), get<1>(adj)));
}
TEST(g0, get_diameter)
{
    EXPECT_EQ(g0.diameter_, get_diameter(get<0>(adj)));
}
TEST(g0, get_average_path_length)
{
    EXPECT_EQ(g0.average_path_length_, get_average_path_length(get<0>(adj)));
}
TEST(g0, get_density)
{
    EXPECT_EQ(g0.density_, get_density(get<0>(adj), get<1>(adj)));
}
// TEST(g0, get_modularity)
// {
//     EXPECT_EQ(g0.modularity_, get_modularity(get<0>(adj), get<1>(adj)));
// }
TEST(g0, get_distance)
{
    EXPECT_EQ(3, get_distance(get<0>(adj), 0, 93, false));
    EXPECT_EQ(3, get_distance(get<0>(adj), 93, 0, false));
    EXPECT_EQ(3, get_distance(get<0>(adj), 20, 11, false));
    EXPECT_EQ(3, get_distance(get<0>(adj), 46, 11, false));
    EXPECT_EQ(4, get_distance(get<0>(adj), 12, 13, false));
    EXPECT_EQ(3, get_distance(get<0>(adj), 88, 0, false));
}