#include <iostream>

using namespace std;

class GraphTest
{
public:
    GraphTest(string path,
    string name,
    int nb_nodes,
    int nb_edges,
    bool is_directed,
    bool is_connected,
    float average_degree,
    float average_weighted_degree,
    float diameter,
    float average_path_length,
    float density,
    float modularity)
    : path_(path), name_(name), nb_nodes_(nb_nodes), nb_edges_(nb_edges), is_directed_(is_directed)
    , is_connected_(is_connected), average_degree_(average_degree)
    , average_weighted_degree_(average_weighted_degree)
    , diameter_(diameter), average_path_length_(average_path_length)
    , density_(density), modularity_(modularity)
    {}
    // ~GraphTest();

    string path_;
    string name_;
    int nb_nodes_;
    int nb_edges_;
    bool is_directed_;
    bool is_connected_;
    float average_degree_;
    float average_weighted_degree_;
    float diameter_;
    float average_path_length_;
    float density_;
    float modularity_;

};