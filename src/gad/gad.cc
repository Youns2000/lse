#include "gad.hh"

using namespace std;

int get_nb_nodes(vector<vector<pair<int, float>>> adj_list)
{
    return adj_list.size();
}

bool contains(vector<pair<int, int>> vec, pair<int, int> elem)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (((vec[i].first == elem.first) && (vec[i].second == elem.second))
        || ((vec[i].first == elem.second) && (vec[i].second == elem.first)))
            return true;
    }
    return false;
}

bool exist(vector<vector<pair<int, float>>> adj_list, int i, int j)
{
    for (size_t k = 0; k < adj_list[i].size(); k++)
    {
        if (get<0>(adj_list[i][k]) == j)
            return true;
    }
    return false;
}

int get_nb_edges(vector<vector<pair<int, float>>> adj_list, bool is_directed)
{
    int total = 0;
    int two = 0;
    vector<pair<int, int>> seen;
    for (size_t i = 0; i < adj_list.size(); i++)
    {
        for (size_t j = 0; j < adj_list[i].size(); j++)
        {
            auto p = make_pair(i, adj_list[i][j].first);
            if (contains(seen, p))
                two++;
            else
            {
                seen.push_back(p);
                total++;
            }
        }
    }
    return is_directed ? (two + total) : total;
}

template <class T>
void print_vec(string name, vector<T> vec)
{
    cout << name << ": ";
    for (size_t i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << "\n";
}

bool is_connected(vector<vector<pair<int, float>>> adj_list)
{
    auto n = get_nb_nodes(adj_list);
    if (n == 0)
        return true;

    vector<bool> touched(n, false);
    touched[0] = true;

    vector<int> todo;
    todo.push_back(0);

    while (!todo.empty())
    {
        int s = todo.back();
        todo.pop_back();
        for (size_t i = 0; i < adj_list[s].size(); i++)
        {
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

bool is_edge_connected(vector<vector<pair<int, float>>> adj_list, bool is_directed)
{
    auto n = get_nb_nodes(adj_list);
    auto m = get_nb_edges(adj_list, is_directed);
    if (n == 0 || m == 0)
        return true;

    vector<bool> touched(n, false);
    int init = adj_list[0][0].first;
    touched[init] = true;
    vector<int> todo;
    todo.push_back(init);

    while (!todo.empty())
    {
        int s = todo.back();
        todo.pop_back();
        for (size_t i = 0; i < adj_list[s].size(); i++)
        {
            if (adj_list[s][i].first >= n)
                continue;
            if (!touched[adj_list[s][i].first])
            {
                touched[adj_list[s][i].first] = true;
                todo.push_back(adj_list[s][i].first);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!(touched[i] || adj_list[i].empty()))
            return false;
    }
    return true;
}

vector<vector<pair<int, float>>> from_edges_to_adj_list(vector<tuple<int, float, int>> edges)
{
    int n = 0;
    for (size_t i = 0; i < edges.size(); i++)
    {
        int f = get<0>(edges[i]);
        int l = get<2>(edges[i]);
        if (f > n)
            n = f;
        if (l > n)
            n = l;
    }

    vector<vector<pair<int, float>>> adj(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        adj[get<0>(edges[i])].push_back(make_pair(get<2>(edges[i]), get<1>(edges[i])));
    }
    return adj;
}


vector<tuple<int, float, int>> from_adj_list_to_edges(vector<vector<pair<int, float>>> adj_list)
{
    vector<tuple<int, float, int>> edges;
    for (size_t i = 0; i < adj_list.size(); i++)
    {
        for (size_t j = 0; j < adj_list[i].size(); j++)
        {
            auto t = make_tuple(j, adj_list[i][j].second, adj_list[i][j].first);
            edges.push_back(t);
        }
    }
    return edges;
}

// O(n*m) 
vector<vector<int>> from_adj_list_to_adj_matrix(vector<vector<pair<int, float>>> adj_list, bool is_directed)
{
    int n = get_nb_nodes(adj_list);
    vector<vector<int>> matrix(n, vector<int>(n, 0));
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

vector<vector<pair<int, float>>> from_directed_to_undirected_graph(vector<vector<pair<int, float>>>& adj_list)
{
    for (size_t i = 0; i < adj_list.size(); i++)
    {
        for (size_t j = 0; j < adj_list[i].size(); j++)
        {
            size_t k = get<0>(adj_list[i][j]);
            if (!exist(adj_list, k, i))
                adj_list[k].push_back(make_pair(i, get<1>(adj_list[i][j])));
        }
    }
    return adj_list;
}

pair<vector<vector<pair<int, float>>>, bool> read_dot(string file_path)
{
    ifstream file_in(file_path);
    if (!file_in.is_open())
        throw ios_base::failure("Error opening file");

    vector<vector<pair<int, float>>> adj_list;
    bool is_directed = false;
    string line;
    getline(file_in, line);
    if (line.find("digraph") != string::npos)
        is_directed = true;
    else if (line.find("graph") != string::npos)
        is_directed = false;
    else
        throw ios_base::failure("Error during parsing first line of the dot file.");
    
    string src_node, dst_node, weight_str, sign;
    int src = 0, dst = 0;
    int index = -1;
    float weight;
    int max = 0;

    while (file_in.good())
    {
        weight = 1.;
        file_in >> src_node;
        if (src_node.compare("}") == 0)
            break;
        else if (src_node.find(";") != string::npos)
        {
            adj_list.push_back(vector<pair<int, float>>());
            index++;
            break;
        }
        file_in >> sign;
        if ((!sign.compare("->") && !is_directed) || (!sign.compare("-") && is_directed))
            throw ios_base::failure("Error with graph orientation and file sign.");
        file_in >> dst_node;
        file_in >> weight_str;
        
        src = stoi(src_node);
        dst = stoi(dst_node);
        if (src > max)
            max = src;
        else if (dst > max)
            max = dst;
        weight = stof(weight_str.substr(weight_str.find("=") + 1, weight_str.find("]") - weight_str.find("=") - 1));

        // cout << src << " " << sign << " " << dst << " [weight=" << weight << "];" << endl;

        if (index < src)
        {
            if (index + 1 == src)
            {
                index++;
                adj_list.push_back(vector<pair<int, float>>());
                adj_list[index].push_back(make_pair(dst, weight));
            }
            else
            {
                for (; index < src; index++)
                    adj_list.push_back(vector<pair<int, float>>());
                adj_list[index].push_back(make_pair(dst, weight));
            }
        }
        else if (src == index)
            adj_list[index].push_back(make_pair(dst, weight));
    }

    if (index < max)
    {
        for (; index < max; index++)
                    adj_list.push_back(vector<pair<int, float>>());
    }

    file_in.close();

    if (!is_directed)
        adj_list = from_directed_to_undirected_graph(adj_list);
    return make_pair(adj_list, is_directed);
}

// GRAPHS METRICS

float get_average_degree(vector<vector<pair<int, float>>> adj_list, bool is_directed)
{
    int avg_deg = 0;
    for (size_t i = 0; i < adj_list.size(); i++)
        avg_deg += adj_list[i].size();
    return ((float)(is_directed ? 1 : 1) * (float)avg_deg) / (float)adj_list.size();
}

float get_average_weighted_degree(vector<vector<pair<int, float>>> adj_list, bool is_directed)
{
    float avg_w_deg = 0;
    for (size_t i = 0; i < adj_list.size(); i++)
    {
        for (size_t j = 0; j < adj_list[i].size(); j++)
            avg_w_deg += adj_list[i][j].second;
    }
    return ((float)(is_directed ? 1 : 1) * (float)avg_w_deg) / (float)adj_list.size();
}

int get_distance(vector<vector<pair<int, float>>>& adj_list, int src, int dst, bool weighted)
{
    auto n = get_nb_nodes(adj_list);

    vector<bool> touched(n, false);
    touched[src] = true;
    
    vector<int> distance(n, 9999);
    distance[src] = 0;

    queue<int> todo;
    todo.push(src);
    
    while (!todo.empty())
    {
        auto s = todo.front();
        todo.pop();

        for (size_t i = 0; i < adj_list[s].size(); i++)
        {
            if (s >= n)
                break;
            if (!touched[adj_list[s][i].first])
            {
                // distance[adj_list[s][i].first] = distance[s] + adj_list[s][i].second;
                distance[adj_list[s][i].first] = distance[s] + (weighted ? adj_list[s][i].second : 1);
                todo.push(adj_list[s][i].first);
                touched[adj_list[s][i].first] = true;
            }
        }
    }
    return distance[dst];
}

int get_diameter(vector<vector<pair<int, float>>> adj_list)
{
    int diameter = 0;
    for (size_t i = 0; i < adj_list.size(); i++)
    {
        for (size_t j = i + 1; j < adj_list.size(); j++)
        {
            int tmp = get_distance(adj_list, i, j, false);
            if (tmp > diameter)
                diameter = tmp;
        }
    }
    return diameter;
}

float get_average_path_length(vector<vector<pair<int, float>>> adj_list)
{
    float avg_p_length = 0.;
    float nb_dist = 0.;

    for (size_t i = 0; i < adj_list.size(); i++)
    {
        for (size_t j = i + 1; j < adj_list.size(); j++)
        {
            float tmp = get_distance(adj_list, i, j, false);
            avg_p_length += tmp;
            nb_dist++;
        }
    }
    return (float)avg_p_length/(float)nb_dist;
}

float get_density(vector<vector<pair<int, float>>> adj_list, bool is_directed)
{
    float n = get_nb_nodes(adj_list);
    float m = get_nb_edges(adj_list, is_directed);
    return m / ((n * (n - 1)) * (is_directed ? 1 : 0.5));
}

// float get_modularity(vector<vector<pair<int, float>>> adj_list, bool is_directed)
// {
//     float modularity = 0.;

//     auto m = get_nb_edges(adj_list, is_directed);
//     auto A = from_adj_list_to_adj_matrix(adj_list);

//     for (size_t i = 0; i < adj_list.size(); i++)
//     {
//     }
    
//     return modularity;
// }

vector<vector<pair<int, float>>> complete_graph_generator(int nb_vertices, unsigned seed, int weights_seed)
{
    vector<vector<pair<int, float>>> adj_list;
    if (nb_vertices <= 0 ||  seed <= 0 || weights_seed <= 0)
        return adj_list;

    vector<pair<int,int>> done;
    for (int i = 0; i < nb_vertices; i++)
    {
        vector<pair<int, float>> tmp_edges;
        for (int j = 0; j < nb_vertices; j++)
        {
            if (i != j)
                tmp_edges.push_back(make_pair(j, (rand() % weights_seed)));
        }
        adj_list.push_back(tmp_edges);
    }
    return adj_list;
}

vector<vector<pair<int, float>>> random_graph_generator(int nb_vertices, int nb_edges, unsigned seed, int weights_seed, bool is_directed)
{
    vector<vector<pair<int, float>>> adj_list;
    if (nb_vertices <= 0 || nb_edges <= 0 || seed <= 0 || weights_seed <= 0)
        return adj_list;

    int moy_edges = nb_edges / nb_vertices;
    int total_edges_placed = 0;
    int rand_nb_edges = 0;
    vector<pair<int, int>> seen;

    srand(time(NULL));
    for (int i = 0; i < nb_vertices; i++)
    {
        vector<pair<int, float>> tmp_edges;
        if (i < nb_vertices - 1)
        {
            rand_nb_edges = moy_edges + ((rand() % 6) - 3);
            total_edges_placed += rand_nb_edges;
        }
        else if (total_edges_placed != nb_edges)
        {
            rand_nb_edges = abs(nb_edges - total_edges_placed);
            total_edges_placed += rand_nb_edges;
        }
        else
            adj_list.push_back(tmp_edges);

        if (is_directed)
        {
            for (int j = 0; j < rand_nb_edges; j++)
                tmp_edges.push_back(make_pair( (rand() % nb_vertices), (rand() % weights_seed)) );
        }
        else
        {
            for (int j = 0; j < rand_nb_edges; j++)
                tmp_edges.push_back(make_pair( (rand() % nb_vertices), (rand() % weights_seed)) );
        }
        adj_list.push_back(tmp_edges);
    }
    return adj_list;
}

void write_dot(const string filename, vector<vector<pair<int, float>>> adj_list, bool is_directed)
{
    ofstream file_out(filename+".dot");
    if (!file_out.is_open())
        throw ios_base::failure("Error opening file");

    vector<pair<int, int>> seen;
    file_out << (is_directed ? "digraph {\n" : "graph {\n");
    for (size_t i = 0; i < adj_list.size(); i++)
    {
        for (size_t j = 0; j < adj_list[i].size(); j++)
        {
            auto p = make_pair(i, adj_list[i][j].first);
            if(is_directed || !contains(seen, p))
            {
                file_out << i << " -" << (is_directed ? "> " : "- ")
                         << adj_list[i][j].first << "[label=\"" << adj_list[i][j].second << "\""
                         << "weight=\"" << adj_list[i][j].second << "\"];\n";
                seen.push_back(p);
            }
        }
    }
    file_out << "}";
    file_out.close();
}

bool convert_to_png(string file_path){
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

void print_graph_props(vector<vector<pair<int, float>>> adj_list, bool is_directed, string name)
{
    cout << name << "(" << (is_directed ? "directed" : "undirected") << ") :" << endl
              << "Nb of nodes: " << get_nb_nodes(adj_list) << endl
              << "Nb of edges: " << get_nb_edges(adj_list, is_directed) << endl
              << "is connected: " << boolalpha << is_connected(adj_list) << endl
              << "is edge connected: " << boolalpha << is_edge_connected(adj_list, is_directed) << endl
              << "average degree: " << get_average_degree(adj_list, is_directed) << endl
              << "average weighted degree: " << get_average_weighted_degree(adj_list, is_directed) << endl
              << "diameter: " << get_diameter(adj_list) << endl
              << "average path length: " << get_average_path_length(adj_list) << endl
              << "density: " << get_density(adj_list, is_directed) << endl << endl;
            //   << "modularity: " << get_modularity(adj_list, is_directed) << endl << endl;
    write_dot(name, adj_list, is_directed);
    convert_to_png(name);
}

void print_adj_list(vector<vector<pair<int, float>>> adj_list)
{
    cout << "Adj_list:" << endl;
    for (size_t i = 0; i < adj_list.size(); i++)
    {
        cout << i << " -> ";
        for (size_t j = 0; j < adj_list[i].size(); j++)
        {
            cout << "(" << adj_list[i][j].first << ", " << adj_list[i][j].second << ") ";
        }
        cout << endl;
    }
}