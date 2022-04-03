#include "graphs.hh"

template <typename T>
int Graph<T>::get_nb_nodes()
{
    return adj_list_.size();
}

template <typename T>
bool contains(std::vector<T> vec, const T& elem)
{
    bool result = false;
    if(find(vec.begin(), vec.end(), elem) != vec.end())
    {
        result = true;
    }
    return result;
}

template <typename T>
int Graph<T>::get_nb_edges()
{
    int total = 0;
    int two = 0;
    std::vector<T> seen;
    for (size_t i = 0; i < adj_list_.size(); i++)
    {
        for (size_t j = 0; j < adj_list_[i].size(); j++)
        {
            if (contains(seen, adj_list_[i][j].first) && contains(seen, i))
                two++;
            else
                total++;
        }
    }
    return is_directed_ ? (two + total) : total;
}

template <typename T>
bool Graph<T>::is_connected()
{
    auto n = get_nb_edges(adj_list_, is_directed_);
    if (n == 0)
        return true;

    std::vector<bool> touched;
    touched.resize(n, false);
    touched[0] = true;

    std::vector<int> todo;
    todo[0] = 0;

    while (!todo.empty())
    {
        auto s = todo.pop_back();
        for (auto& d : adj_list_[s])
        {
            if (!touched[d])
            {
                touched[d] = true;
                todo.push_back(d);
            }
        }
    }
    auto sum = 0;
    for (auto& b : touched)
    {
        if (b)
            sum++;
    }
    return sum == n;
}

template <typename T>
bool Graph<T>::is_edge_connected()
{
    return true;
}

template <typename T>
std::vector<std::tuple<T, float, T>> Graph<T>::from_adj_list_to_edges()
{
    std::vector<std::tuple<T, float, T>> edges;
    for (size_t i = 0; i < adj_list_.size(); i++)
    {
        for (size_t j = 0; j < adj_list_[i].size(); j++)
        {
            auto t = std::make_tuple(j, adj_list_[i][j].second, adj_list_[i][j].first);
            edges.push_back(t);
        }
    }

    // std::cout << is_directed_ << std::endl;
    return edges;
}

template <typename T>
int Graph<T>::get_average_degree()
{
    int avg_deg = 0;
    //FIXME
    return avg_deg;
}

template <typename T>
int Graph<T>::get_average_weighted_degree()
{
    int avg_w_deg = 0;
    //FIXME
    return avg_w_deg;
}

template <typename T>
int Graph<T>::get_average_path_length()
{
    int avg_p_length = 0;
    //FIXME
    return avg_p_length;
}

template <typename T>
float Graph<T>::get_density()
{
    float density = 0.;
    return density;
}

template <typename T>
float Graph<T>::get_modularity()
{
    float modularity = 0.;
    return modularity;
}

template <typename T>
std::vector<std::vector<std::pair<int, float>>> Graph<T>::int_graph_generator(int nb_vertices, int nb_edges, unsigned seed, int weights_seed)
{
    std::vector<std::vector<std::pair<int, float>>> adj_list;
    int moy_edges = nb_edges / nb_vertices;

    int total_edges_placed = 0;
    int rand_nb_edges = 0;
    srand(seed);
    for (int i = 0; i < nb_vertices; i++)
    {
        if (total_edges_placed != nb_edges)
        {
            rand_nb_edges = (rand() % (moy_edges + 2)) + (moy_edges == 0 ? 0 : (moy_edges - 2));
            total_edges_placed += rand_nb_edges;
            // std::cout << rand_nb_edges << '\n';
        }
        std::vector<std::pair<int, float>> tmp_edges;
        for (int j = 0; j < rand_nb_edges; j++)
            tmp_edges.push_back(std::make_pair((rand() % seed), (rand() % weights_seed)));
        adj_list.push_back(tmp_edges);
    }
    return adj_list;
}
 
template <typename T>
void Graph<T>::graphs_save(const std::string filename)
{
    std::ofstream file_out(filename+".dot");
    if (!file_out.is_open())
        throw std::ios_base::failure("Error opening file");

    auto edge_list = from_adj_list_to_edges();

    file_out << (is_directed_ ? "digraph {\n" : "graph {\n");
    for (size_t i = 0; i < edge_list.size(); i++)
    {
        file_out << std::get<0>(edge_list[i]) << " -" << (is_directed_ ? "> " : "- ") 
                 << std::get<2>(edge_list[i]) << "[label=\"" << std::get<1>(edge_list[i]) << "\"" 
                 << "weight=\"" << std::get<1>(edge_list[i]) << "\"];\n";
    }
    file_out << "}";
    file_out.close();
}

template <typename T>
bool Graph<T>::convert_to_png(const std::string filename){
    GVC_t *gvc;
    Agraph_t *g;
    FILE *fp;
    gvc = gvContext();
    fp = fopen((filename+".dot").c_str(), "r");
    g = agread(fp, 0);
    gvLayout(gvc, g, "dot");
    gvRender(gvc, g, "png", fopen((filename+".png").c_str(), "w"));
    gvFreeLayout(gvc, g);
    agclose(g);
    return (gvFreeContext(gvc));
}

// #include "graphs.hh"

// template <class T>
// int get_nb_nodes(std::vector<std::vector<std::pair<T, float>>> adj_list)
// {
//     return adj_list.size();
// }

// template <class T>
// int get_nb_edges(std::vector<std::vector<std::pair<T, float>>> adj_list, bool is_directed_)
// {
//     int total = 0;
//     for (auto& v : adj_list)
//     {
//         total += v.size();
//     }
//     return is_directed_ ? total : total / 2;
// }

// template <class T>
// bool is_connected(std::vector<std::vector<std::pair<T, float>>> adj_list, bool is_directed_)
// {
//     auto n = get_nb_edges(adj_list, is_directed_);
//     if (n == 0)
//         return true;

//     std::vector<bool> touched;
//     touched.resize(n, false);
//     touched[0] = true;

//     std::vector<int> todo;
//     todo[0] = 0;

//     while (!todo.empty())
//     {
//         auto s = todo.pop_back();
//         for (auto& d : adj_list[s])
//         {
//             if (!touched[d])
//             {
//                 touched[d] = true;
//                 todo.push_back(d);
//             }
//         }
//     }
//     auto sum = 0;
//     for (auto& b : touched)
//     {
//         if (b)
//             sum++;
//     }
//     return sum == n;
// }

// template <class T>
// bool is_edge_connected(std::vector<std::vector<std::pair<T, float>>> adj_list)
// {
//     return true;
// }

// template <class T>
// std::vector<std::vector<std::pair<T, float>>> from_edges_to_adj_list(std::vector<std::tuple<T, float, T>>)
// {
//     //FIXME
//     return nullptr;
// }

// template <class T>
// std::vector<std::tuple<T, float, T>> from_adj_list_to_edges(std::vector<std::vector<std::pair<T, float>>> adj_list, bool is_directed_)
// {
//     std::vector<std::tuple<T, float, T>> edges;
//     for (size_t i = 0; i < adj_list.size(); i++)
//     {
//         for (size_t j = 0; j < adj_list[i].size(); j++)
//         {
//             auto t = std::make_tuple(j, adj_list[i][j].second, adj_list[i][j].first);
//             edges.push_back(t);
//         }
//     }

//     std::cout << is_directed_ << std::endl;
//     return edges;
// }

// template <class T>
// int get_average_degree(std::vector<std::vector<std::pair<T, float>>> adj_list)
// {
//     int avg_deg = 0;
//     //FIXME
//     return avg_deg;
// }

// template <class T>
// int get_average_weighted_degree(std::vector<std::vector<std::pair<T, float>>> adj_list)
// {
//     int avg_w_deg = 0;
//     //FIXME
//     return avg_w_deg;
// }

// template <class T>
// int get_average_path_length(std::vector<std::vector<std::pair<T, float>>> adj_list)
// {
//     int avg_p_length = 0;
//     //FIXME
//     return avg_p_length;
// }

// template <class T>
// float get_density(std::vector<std::vector<std::pair<T, float>>> adj_list)
// {
//     float density = 0.;
//     return density;
// }

// template <typename T>
// float get_modularity(const std::vector<std::vector<std::pair<T, float>>>& adj_list)
// {
//     float modularity = 0.;
//     return modularity;
// }

// // template <class T>
// // float get_modularity(const std::vector<std::vector<std::pair<T, float>>>& adj_list)
// // {
// //     float modularity = 0.;
// //     return modularity;
// // }



// std::vector<std::vector<std::pair<int, float>>> int_graph_generator(int nb_vertices, int nb_edges, unsigned seed, int weights_seed, const std::string filename, bool is_directed_)
// {
//     std::vector<std::vector<std::pair<int, float>>> adj_list;
//     int moy_edges = nb_edges / nb_vertices;

//     int total_edges_placed = 0;
//     int rand_nb_edges = 0;
//     srand(seed);
//     for (int i = 0; i < nb_vertices; i++)
//     {
//         if (total_edges_placed != nb_edges)
//         {
//             rand_nb_edges = (rand() % (moy_edges + 2)) + (moy_edges == 0 ? 0 : (moy_edges - 2));
//             total_edges_placed += rand_nb_edges;
//             // std::cout << rand_nb_edges << '\n';
//         }
//         std::vector<std::pair<int, float>> tmp_edges;
//         for (int j = 0; j < rand_nb_edges; j++)
//             tmp_edges.push_back(std::make_pair((rand() % seed), (rand() % weights_seed)));
//         adj_list.push_back(tmp_edges);
//     }

//     std::ofstream file_out(filename+".dot");
//     if (!file_out.is_open())
//         throw std::ios_base::failure("Error opening file");

//     auto edge_list = from_adj_list_to_edges(adj_list, is_directed_);

//     file_out << (is_directed_ ? "digraph {\n" : "graph {\n");
//     for (size_t i = 0; i < edge_list.size(); i++)
//     {
//         file_out << std::get<0>(edge_list[i]) << " -" << (is_directed_ ? "> " : "- ") 
//                  << std::get<2>(edge_list[i]) << "[label=\"" << std::get<1>(edge_list[i]) << "\"" 
//                  << "weight=\"" << std::get<1>(edge_list[i]) << "\"];\n";
//     }
//     file_out << "}";
//     file_out.close();

//     return adj_list;
// }

// // template <class T>
// // void graphs_save(const std::string filename, std::vector<std::vector<std::pair<T, float>>> adj_list, bool is_directed_)
// // {
// //     std::ofstream file_out(filename+".dot");
// //     if (!file_out.is_open())
// //         throw std::ios_base::failure("Error opening file");

// //     auto edge_list = from_adj_list_to_edges(adj_list);

// //     file_out << (is_directed_ ? "digraph {\n" : "graph {\n");
// //     for (int i = 0; i < edge_list.size(); i++)
// //     {
// //         file_out << edge_list[i][0] << " -" << (is_directed_ ? "> " : "- ") 
// //                  << edge_list[i][2] << "[label=\"" << edge_list[i][1] << "\"" 
// //                  << "weight=\"" << edge_list[i][1] << "\"];\n";
// //     }
// //     file_out << "}";
// //     file_out.close();
// // }

// bool convert_to_png(std::string file_path){
//     GVC_t *gvc;
//     Agraph_t *g;
//     FILE *fp;
//     gvc = gvContext();
//     fp = fopen((file_path+".dot").c_str(), "r");
//     g = agread(fp, 0);
//     gvLayout(gvc, g, "dot");
//     gvRender(gvc, g, "png", fopen((file_path+".png").c_str(), "w"));
//     gvFreeLayout(gvc, g);
//     agclose(g);
//     return (gvFreeContext(gvc));
// }