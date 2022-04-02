#include "graphs.hh"

template <class T>
int get_nb_nodes(std::vector<std::vector<std::pair<T, float>>> adj_list)
{
    return adj_list.size();
}

template <class T>
int get_nb_edges(std::vector<std::vector<std::pair<T, float>>> adj_list, bool is_directed)
{
    int total = 0;
    for (auto& v : adj_list)
    {
        total += v.size();
    }
    return is_directed ? total : total / 2;
}

template <class T>
bool is_connected(std::vector<std::vector<std::pair<T, float>>> adj_list, bool is_directed)
{
    auto n = get_nb_edges(adj_list, is_directed);
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
        for (auto& d : adj_list[s])
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

template <class T>
bool is_edge_connected(std::vector<std::vector<std::pair<T, float>>> adj_list)
{
    return true;
}

template <class T>
std::vector<std::vector<std::pair<T, float>>> from_edges_to_adj_list(std::vector<std::tuple<T, float, T>>)
{
    //FIXME
    return nullptr;
}

template <class T>
std::vector<std::tuple<T, float, T>> from_adj_list_to_edges(std::vector<std::vector<std::pair<T, float>>> adj_list, bool is_directed)
{
    std::vector<std::tuple<T, float, T>> edges;
    for (size_t i = 0; i < adj_list.size(); i++)
    {
        for (auto& j : adj_list[i])
        {
            edges.push_back(make_tuple(j, adj_list[i][1], adj_list[i][0]));
        }
    }
    return edges;
}

template <class T>
int get_average_degree(std::vector<std::vector<std::pair<T, float>>> adj_list)
{
    int avg_deg = 0;
    //FIXME
    return avg_deg;
}

template <class T>
int get_average_weighted_degree(std::vector<std::vector<std::pair<T, float>>> adj_list)
{
    int avg_w_deg = 0;
    //FIXME
    return avg_w_deg;
}

template <class T>
int get_average_path_length(std::vector<std::vector<std::pair<T, float>>> adj_list)
{
    int avg_p_length = 0;
    //FIXME
    return avg_p_length;
}

template <class T>
float get_density(std::vector<std::vector<std::pair<T, float>>> adj_list)
{
    float density = 0.;
    return density;
}

template <class T>
float get_modularity(std::vector<std::vector<std::pair<T, float>>> adj_list)
{
    float modularity = 0.;
    return modularity;
}

std::vector<std::vector<std::pair<int, float>>> int_graph_generator(int nb_vertices, int nb_edges, unsigned seed, int weights_seed)
{
    std::vector<std::vector<std::pair<int, float>>> adj_list;
    int moy_edges = nb_edges / nb_vertices;

    srand(seed);
    for (int i = 0; i < nb_vertices; i++)
    {
        int rand_nb_edges = (rand() % (moy_edges + 2)) + moy_edges - 2;
        std::vector<std::pair<int, float>> tmp_edges;
        for (int j = 0; j < rand_nb_edges; j++)
            tmp_edges.push_back(std::make_pair((rand() % seed), (rand() % weights_seed)));
        adj_list.push_back(tmp_edges);
    }
    return adj_list;
}

template <class T>
void graphs_save(std::string filename, std::vector<std::vector<std::pair<T, float>>> adj_list, bool is_directed)
{
    std::ofstream file_out(filename+".dot");
    if (!file_out.is_open())
        throw std::ios_base::failure("Error opening file");

    auto edge_list = from_adj_list_to_edges(adj_list);

    file_out << (is_directed ? "digraph {\n" : "graph {\n");
    for (int i = 0; i < edge_list.size(); i++)
    {
        file_out << edge_list[i][0] << " -" << (is_directed ? "> " : "- ") 
                 << edge_list[i][2] << "[label=\"" << edge_list[i][1] << "\"" 
                 << "weight=\"" << edge_list[i][1] << "\"];\n";
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



/*



template <typename T>
Graph<T> Graph<T>::add_edges(std::vector<Edge<T>> edges)
{
    if (!edges.empty())
    {
        for (auto& e : edges)
            edges_.push_back(e);
    }
    return *this;
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
int Graph<T>::get_nb_nodes()
{
    int total = 0;
    std::vector<T> vec;
    for (auto& e : edges_)
    {
        if (e.src_ == e.dest_ && !contains(vec, e.src_))
        {
            vec.push_back(e.src_);
            total += 1;
        }
        else
        {
            if (!contains(vec, e.src_))
            {
                vec.push_back(e.src_);
                total += 1;
            }
            if (!contains(vec, e.dest_))
            {
                vec.push_back(e.dest_);
                total += 1;
            }
        }
    }
    return total;
}

template <typename T>
int Graph<T>::get_nb_edges()
{
    return edges_.size();
}

template <typename T>
bool Graph<T>::is_connected()
{
    auto n = edges_.size();
    if (n == 0)
        return true;

    auto adj_list = this->convert_to_adjancy_list();

    std::vector<bool> touched;
    for (auto& i : touched)
        i = false;
    touched[0] = true;
    std::vector<int> todo;
    todo[0] = 0;

    while (!todo.empty())
    {
        auto s = todo.pop_back();
        for (auto& d : adj_list[s])
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
vector<vector<pair<T, T>>> Graph<T>::convert_to_adjancy_list()
{
    vector<vector<pair<T, T>>> adj_list;
    adj_list.reserve(edges_.size());

    for (auto& e : edges_)
    {
        adj_list[e.src_].push_back(make_pair(e.dest_, e.data_));    
    }
    return adj_list;
}

template <typename T>
int Graph<T>::average_degree()
{
    auto average = 0;
    auto adj_list = this->convert_to_adjancy_list();

    for (auto& i : adj_list)
    {
        if (!directed_)
            average += i.size();
    }

    return average/adj_list.size();
}

template <typename T>
float Graph<T>::density()
{
    auto nb_nodes = get_nb_nodes();
    float res = get_nb_edges() / (nb_nodes * (nb_nodes - 1));
    if (directed_)
        res *= 2;
    return res;
}

*/