#include "graphs.hh"

// template <typename T>
// Graph<T>::Graph([std::vector<Edge> edges]) : edges_(edges)
// {
// }

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
    if( find(vec.begin(), vec.end(), elem) != vec.end() )
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
    return true;
}
