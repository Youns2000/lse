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
        6,
        0,
        5,
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

TEST(Metrics, get_nb_nodes)
{
    for (auto& g : graphs)
    {
        EXPECT_EQ(g.nb_nodes_, get_nb_nodes(get<0>(adj)));
    }
}

TEST(G0, get_nb_edges)
{
    EXPECT_EQ(g0.nb_edges_, get_nb_edges(get<0>(adj), get<1>(adj)));
}

// TEST(Basics, get_nb_nodes)
// {
    
//     EXPECT_EQ(9, get_nb_nodes(adj));
// }

// TEST(graphlib_tests, get_nb_edges)
// {
//     Graph<int> g;
//     g.add_edges({{1, 2, 3}, {0, 6, 1}, {2, 3, 1}, {1, 2, 90}});

//     vector<vector<pair<int, int>>> expected_adj_list = 
//     {
//         {make_pair(1, 6)},
//         {make_pair(3, 2), make_pair(90, 2)},
//         {make_pair(1, 3)}
//     };

//     vector<vector<pair<int, int>>> adj_list = g.convert_to_adjancy_list();

//     EXPECT_EQ(adj_list.size(), expected_adj_list.size());
//     EXPECT_EQ(adj_list, expected_adj_list);

//     for (size_t i = 0; i < expected_adj_list.size(); i++)
//     {
//         EXPECT_EQ(adj_list[i], expected_adj_list[i]);   
//     }
// }

// TEST(graphlib_tests, is_connected)
// {
//     Graph<int> g;
//     g.add_edges({{1, 2, 3}, {0, 6, 1}, {2, 3, 1}, {1, 2, 90}});

//     vector<vector<pair<int, int>>> expected_adj_list = 
//     {
//         {make_pair(1, 6)},
//         {make_pair(3, 2), make_pair(90, 2)},
//         {make_pair(1, 3)}
//     };

//     vector<vector<pair<int, int>>> adj_list = g.convert_to_adjancy_list();

//     EXPECT_EQ(adj_list.size(), expected_adj_list.size());
//     EXPECT_EQ(adj_list, expected_adj_list);

//     for (size_t i = 0; i < expected_adj_list.size(); i++)
//     {
//         EXPECT_EQ(adj_list[i], expected_adj_list[i]);   
//     }
// }
// TEST(graphlib_tests, graph_to_adj_list)
// {
//     Graph<int> g;
//     g.add_edges({{1, 2, 3}, {0, 6, 1}, {2, 3, 1}, {1, 2, 90}});

//     vector<vector<pair<int, int>>> expected_adj_list = 
//     {
//         {make_pair(1, 6)},
//         {make_pair(3, 2), make_pair(90, 2)},
//         {make_pair(1, 3)}
//     };

//     vector<vector<pair<int, int>>> adj_list = g.convert_to_adjancy_list();

//     EXPECT_EQ(adj_list.size(), expected_adj_list.size());
//     EXPECT_EQ(adj_list, expected_adj_list);

//     for (size_t i = 0; i < expected_adj_list.size(); i++)
//     {
//         EXPECT_EQ(adj_list[i], expected_adj_list[i]);   
//     }
// }