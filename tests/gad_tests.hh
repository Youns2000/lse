#include "../src/gad/gad.hh"
#include <gtest/gtest.h>

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

struct graph_test
{
    string path;
    string name;
    int nb_nodes;
    int nb_edges;
    bool is_connected;
    bool is_edge_connected;
    float average_degree;
    float average_weighted_degree;
    float diameter;
    float average_path_length;
    float density;
    float modularity;
};

struct graph_test g0;
g0.path = "graphs_sets/G0.dot";
g0.path = "graphs_sets/G0.dot";
g0.path = "graphs_sets/G0.dot";



TEST(Basics, get_nb_edges)
{
    
    EXPECT_EQ(8, get_nb_edges(adj, false));
}

TEST(Basics, get_nb_nodes)
{
    
    EXPECT_EQ(9, get_nb_nodes(adj));
}

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