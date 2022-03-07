#include "../src/graphslib/graphs.hh"
#include "../src/graphslib/graphs.cc"
#include <gtest/gtest.h>

TEST(graphlib_tests, edges_class)
{
    auto e = Edge<int>{1, 2, 3};
    auto e2 = Edge(4,5,6);

    testing::internal::CaptureStdout();
    std::cout << e << "\n" << e2;
    std::string output = testing::internal::GetCapturedStdout();
    std::string exp = "(1, 2, 3)\n(4, 5, 6)";
    EXPECT_EQ(output, exp);
}

TEST(graphlib_tests, graphs_basics)
{
    testing::internal::CaptureStdout();
    Graph<int> g;
    g.add_edges({{1, 2, 3}, {0, 6, 1}, {2, 3, 1}});
    std::cout << g;
    std::string output = testing::internal::GetCapturedStdout();

    g.add_edges({{1, 2, 90}});

    std::string exp = "(1, 2, 3)\n(0, 6, 1)\n(2, 3, 1)\n";
    EXPECT_EQ(output, exp);
    EXPECT_EQ(g.get_nb_nodes(), 5);
    EXPECT_EQ(g.get_nb_edges(), 4);
}

TEST(graphlib_tests, graph_to_adj_list)
{
    Graph<int> g;
    g.add_edges({{1, 2, 3}, {0, 6, 1}, {2, 3, 1}, {1, 2, 90}});

    vector<vector<pair<int, int>>> expected_adj_list = 
    {
        {make_pair(1, 6)},
        {make_pair(3, 2), make_pair(90, 2)},
        {make_pair(1, 3)}
    };

    // vector<vector<pair<int, int>>> adj_list = g.convert_to_adjancy_list();

    // EXPECT_EQ(adj_list.size(), expected_adj_list.size());
    // EXPECT_EQ(adj_list, expected_adj_list);

    // for (size_t i = 0; i < expected_adj_list.size(); i++)
    // {
    //     ASSERT_THAT(adj_list[i], expected_adj_list[i]);   
    // }
}