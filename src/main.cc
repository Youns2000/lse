#include "graphslib/graphs.hh"

using namespace std;

// template <class T>
// void graphs_save(std::string filename, std::vector<std::vector<std::pair<T, float>>> adj_list, bool is_directed)
// {
//     std::ofstream file_out(filename+".dot");
//     if (!file_out.is_open())
//         throw std::ios_base::failure("Error opening file");

//     std::vector<std::tuple<int, float, int>> edge_list = from_adj_list_to_edges(adj_list);

//     file_out << (is_directed ? "digraph {\n" : "graph {\n");
//     for (int i = 0; i < edge_list.size(); i++)
//     {
//         file_out << edge_list[i][0] << " -" << (is_directed ? "> " : "- ") 
//                  << edge_list[i][2] << "[label=\"" << edge_list[i][1] << "\"" 
//                  << "weight=\"" << edge_list[i][1] << "\"];\n";
//     }
//     file_out << "}";
//     file_out.close();
// }



int main()
{
    std::vector<std::vector<std::pair<int, float>>> adj_l = int_graph_generator(100, 70, 1, 5);
    graphs_save<int>("test_graph", adj_l, false);
    convert_to_png("test_graph");

    return 0;
}