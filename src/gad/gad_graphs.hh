#pragma once

#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <graphviz/gvc.h>

class Graph
{
public:
    Graph(bool is_directed, std::vector<std::vector<std::pair<int, float>>> adj_list)
    : is_directed_(is_directed)
    , adj_list_(adj_list)
    {}

    int get_nb_nodes();

    bool is_directed_;
    std::vector<std::vector<std::pair<int, float>>> adj_list_;
};