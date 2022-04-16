#include "../src/gad/gad.hh"
#include <gtest/gtest.h>
#include "graph_test.hh"

using namespace std;

auto g0 = GraphTest {
        "graphs_sets/G0.dot",
        "G0",
        100,
        300,
        false,
        true,
        6.,
        0.,
        5.,
        2.7264646464646463,
        0.06060606060606061,
        0
    };
auto g1 = GraphTest {
        "graphs_sets/G1.dot",
        "G1",
        100,
        300,
        false,
        true,
        0,
        0,
        7,
        3.351357037660425,
        0.042078687144961074,
        0
    };
auto g2 = GraphTest {
        "graphs_sets/G0.dot",
        "G0",
        100,
        300,
        false,
        true,
        0,
        0,
        7,
        3.351357037660425,
        0.042078687144961074,
        0
    };
auto g3 = GraphTest {
        "graphs_sets/G0.dot",
        "G0",
        100,
        300,
        false,
        true,
        0,
        0,
        7,
        3.351357037660425,
        0.042078687144961074,
        0
    };
auto g4 = GraphTest {
        "graphs_sets/G0.dot",
        "G0",
        100,
        300,
        false,
        true,
        0,
        0,
        7,
        3.351357037660425,
        0.042078687144961074,
        0
    };

vector graphs = {g0, g1, g2, g3, g4};
auto adj = read_dot("./tests/graphs_sets/G0.dot");
TEST(G0, get_nb_nodes)
{
    EXPECT_EQ(g0.nb_nodes_, get_nb_nodes(get<0>(adj)));
}
TEST(G0, get_nb_edges)
{
    EXPECT_EQ(g0.nb_edges_, get_nb_edges(get<0>(adj), get<1>(adj)));
}
TEST(G0, is_connected)
{
    EXPECT_EQ(g0.is_connected_, is_connected(get<0>(adj)));
}
TEST(G0, get_average_degree)
{
    EXPECT_EQ(g0.average_degree_, get_average_degree(get<0>(adj), get<1>(adj)));
}
TEST(G0, get_average_weighted_degree)
{
    EXPECT_EQ(g0.average_weighted_degree_, get_average_weighted_degree(get<0>(adj), get<1>(adj)));
}
TEST(G0, get_diameter)
{
    EXPECT_EQ(g0.diameter_, get_diameter(get<0>(adj)));
}
TEST(G0, get_average_path_length)
{
    EXPECT_EQ(g0.average_path_length_, get_average_path_length(get<0>(adj)));
}
TEST(G0, get_density)
{
    EXPECT_EQ(g0.density_, get_density(get<0>(adj), get<1>(adj)));
}
// TEST(G0, get_distance)
// {
//     EXPECT_EQ(g0.density_, get_density(get<0>(adj), get<1>(adj)));
    
// }