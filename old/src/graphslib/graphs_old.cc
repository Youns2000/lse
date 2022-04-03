#include "graphs.h"

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

