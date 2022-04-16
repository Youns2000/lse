#include "../src/gad/gad.hh"
#include <gtest/gtest.h>
#include "graph_test.hh"

using namespace std;

vector<vector<pair<int, float>>> adj = 
{
    {
        {make_pair(1, 6.), make_pair(2, 6.)},
        {make_pair(3, 6.), make_pair(4, 6.)},
        {make_pair(5, 6.), make_pair(6, 6.)},
        {make_pair(7, 6.), make_pair(8, 6.)},
        {}, {}, {}, {}, {}
    }
};

auto g0 = GraphTest {
        "graphs_sets/G0.dot",
        "G0",
        100,
        200,
        false,
        true,
        0,
        0,
        7,
        3.351357037660425,
        0.042078687144961074,
        0
    };

TEST(Basics, get_nb_edges)
{
    auto adj = read_dot("graphs_sets/G0.dot");
    EXPECT_EQ(g0.nb_edges, get_nb_edges(get<0>(adj), get<1>(adj)));
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