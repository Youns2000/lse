#include "gad.hh"

int get_nb_nodes(std::vector<std::vector<std::pair<int, float>>> adj_list)
{
    return adj_list.size();
}

bool contains(std::vector<std::pair<int, int>> vec, std::pair<int, int> elem)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        if ((vec[i].first == elem.first) && (vec[i].second == elem.second))
            return true;
    }
    return false;
}

int get_nb_edges(std::vector<std::vector<std::pair<int, float>>> adj_list, bool is_directed)
{
    int total = 0;
    int two = 0;
    std::vector<std::pair<int, int>> seen;
    for (size_t i = 0; i < adj_list.size(); i++)
    {
        for (size_t j = 0; j < adj_list[i].size(); j++)
        {
            if (contains(seen, std::make_pair(i, adj_list[i][j].first)))
                two++;
            else
            {
                seen.push_back(std::make_pair(i, adj_list[i][j].first));
                total++;
            }
        }
    }
    return is_directed ? (two + total) : total;
}

template <class T>
void print_vec(std::string name, std::vector<T> vec)
{
    std::cout << name << ": ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << "\n";
}

bool is_connected(std::vector<std::vector<std::pair<int, float>>> adj_list)
{
    auto n = get_nb_nodes(adj_list);
    if (n == 0)
        return true;

    std::vector<bool> touched(n, false);
    touched[0] = true;

    std::vector<int> todo;
    todo.push_back(0);

    while (!todo.empty())
    {
        int s = todo.back();
        todo.pop_back();
        for (size_t i = 0; i < adj_list[s].size(); i++)
        {
            // std::cout << s << i << std::endl;
            if (adj_list[s][i].first >= n)
                continue;
            if (!touched[adj_list[s][i].first])
            {
                touched[adj_list[s][i].first] = true;
                todo.push_back(adj_list[s][i].first);
            }
        }
    }
    for (size_t i = 0; i < touched.size(); i++)
    {
        if (!touched[i])
            return false;
    }
    return true;
}

bool is_edge_connected(std::vector<std::vector<std::pair<int, float>>> adj_list, bool is_directed)
{
    auto n = get_nb_nodes(adj_list);
    auto m = get_nb_edges(adj_list, is_directed);
    if (n == 0 || m == 0)
        return true;

    std::vector<bool> touched(n, false);
    

    return true;
}

// std::vector<std::vector<std::pair<int, float>>> from_edges_to_adj_list(std::vector<std::tuple<int, float, int>>)
// {
//     std::vector<std::vector<std::pair<int, float>>> l;
//     //FIXME
//     return l;
// }


std::vector<std::tuple<int, float, int>> from_adj_list_to_edges(std::vector<std::vector<std::pair<int, float>>> adj_list, bool is_directed)
{
    std::vector<std::tuple<int, float, int>> edges;
    for (size_t i = 0; i < adj_list.size(); i++)
    {
        for (size_t j = 0; j < adj_list[i].size(); j++)
        {
            auto t = std::make_tuple(j, adj_list[i][j].second, adj_list[i][j].first);
            edges.push_back(t);
        }
    }

    std::cout << is_directed << std::endl;
    return edges;
}

// Time Complexity: O(N*M) 
// Auxiliary Space: O(N2)
std::vector<std::vector<int>> from_adj_list_to_adj_matrix(std::vector<std::vector<std::pair<int, float>>> adj_list, bool is_directed)
{
    int n = get_nb_nodes(adj_list);
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (auto& j : adj_list[i])
        {
            if (!is_directed)
                matrix[j.first][i] = j.second;
            matrix[i][j.first] = j.second;
        }
    }
    return matrix;
}


float get_average_degree(std::vector<std::vector<std::pair<int, float>>> adj_list)
{
    int avg_deg = 0;
    for (size_t i = 0; i < adj_list.size(); i++)
        avg_deg += adj_list[i].size();
    return (float)avg_deg / (float)adj_list.size();
}

float get_average_weighted_degree(std::vector<std::vector<std::pair<int, float>>> adj_list)
{
    float avg_w_deg = 0;
    for (size_t i = 0; i < adj_list.size(); i++)
    {
        for (size_t j = 0; j < adj_list[i].size(); j++)
            avg_w_deg += adj_list[i][j].second;
    }
    return (float)avg_w_deg / (float)adj_list.size();
}


// int get_average_path_length(std::vector<std::vector<std::pair<int, float>>> adj_list)
// {
//     int avg_p_length = 0;
//     //FIXME
//     return avg_p_length;
// }


// float get_density(std::vector<std::vector<std::pair<int, float>>> adj_list)
// {
//     float density = 0.;
//     return density;
// }

// template <typename T>
// float get_modularity(const std::vector<std::vector<std::pair<int, float>>>& adj_list)
// {
//     float modularity = 0.;
//     return modularity;
// }

// 
// float get_modularity(const std::vector<std::vector<std::pair<int, float>>>& adj_list)
// {
//     float modularity = 0.;
//     return modularity;
// }

std::vector<std::vector<std::pair<int, float>>> complete_graph_generator(int nb_vertices, unsigned seed, int weights_seed)
{
    std::vector<std::vector<std::pair<int, float>>> adj_list;
    if (nb_vertices <= 0 ||  seed <= 0 || weights_seed <= 0)
        return adj_list;

    std::vector<std::pair<int,int>> done;
    for (int i = 0; i < nb_vertices; i++)
    {
        std::vector<std::pair<int, float>> tmp_edges;
        for (int j = 0; j < nb_vertices; j++)
        {
            if (i != j)
            {
                auto p = std::make_pair(i, j);
                auto p1 = std::make_pair(j, i);
                if (!contains(done, p) && !contains(done, p1))
                {
                    tmp_edges.push_back(std::make_pair(j, (rand() % weights_seed)));
                    done.push_back(std::make_pair(i, j));
                }
            }
        }
        adj_list.push_back(tmp_edges);
    }
    return adj_list;
}

std::vector<std::vector<std::pair<int, float>>> random_graph_generator(int nb_vertices, int nb_edges, unsigned seed, int weights_seed)
{
    std::vector<std::vector<std::pair<int, float>>> adj_list;
    if (nb_vertices <= 0 || nb_edges <= 0 || seed <= 0 || weights_seed <= 0)
        return adj_list;

    int moy_edges = nb_edges / nb_vertices;
    int total_edges_placed = 0;
    int rand_nb_edges = 0;

    int min = ((moy_edges - 2 > 0) ? (moy_edges - 2) : 0);
    int max = moy_edges + 2;

    std::cout << "min:" << min << "max:" << max << std::endl;

    srand(time(0));

    for (int i = 0; i < nb_vertices; i++)
    {
        if ((i < nb_vertices - 1) || (total_edges_placed == nb_edges))
        {
            rand_nb_edges = (rand() % max) + min;
            total_edges_placed += rand_nb_edges;
        }
        else
        {
            rand_nb_edges = (nb_edges - total_edges_placed);
            total_edges_placed = nb_edges;
        }

        std::vector<std::pair<int, float>> tmp_edges;
        for (int j = 0; j < rand_nb_edges; j++)
            tmp_edges.push_back(std::make_pair( (rand() % nb_vertices), (rand() % weights_seed)) );
        adj_list.push_back(tmp_edges);
    }

    return adj_list;
}

void graphs_save(const std::string filename, std::vector<std::vector<std::pair<int, float>>> adj_list, bool is_directed)
{
    std::ofstream file_out(filename+".dot");
    if (!file_out.is_open())
        throw std::ios_base::failure("Error opening file");

    file_out << (is_directed ? "digraph {\n" : "graph {\n");
    for (size_t i = 0; i < adj_list.size(); i++)
    {
        for (size_t j = 0; j < adj_list[i].size(); j++)
        {
            file_out << i << " -" << (is_directed ? "> " : "- ") 
                 << adj_list[i][j].first << "[label=\"" << adj_list[i][j].second << "\"" 
                 << "weight=\"" << adj_list[i][j].second << "\"];\n";
        }
    }
    file_out << "}";
    file_out.close();
}

bool convert_to_png(std::string file_path){
    GVC_t *gvc;
    Agraph_t *g;
    FILE *fp;
    gvc = gvContext();
    fp = fopen((file_path+".dot").c_str(), "r");
    g = agread(fp, 0);
    gvLayout(gvc, g, "dot");
    gvRender(gvc, g, "png", fopen((file_path+".png").c_str(), "w"));
    gvFreeLayout(gvc, g);
    agclose(g);
    return (gvFreeContext(gvc));
}

void graph_print_params(std::vector<std::vector<std::pair<int, float>>> adj_list, bool is_directed, std::string name)
{
    std::cout << name << "(" << (is_directed ? "directed" : "undirected") << ") :" << std::endl
              << "Nb of nodes: " << get_nb_nodes(adj_list) << std::endl
              << "Nb of edges: " << get_nb_edges(adj_list, is_directed) << std::endl
              << "is connected: " << std::boolalpha << is_connected(adj_list) << std::endl
              << "average degree: " << get_average_degree(adj_list) << std::endl
              << "average weighted degree: " << get_average_weighted_degree(adj_list) << std::endl << std::endl;
    graphs_save(name, adj_list, is_directed);
    convert_to_png(name);
}