#include <iostream>

using namespace std;

class GraphTest
{
public:
    // GraphTest(string path)
    // : path_(path), path_(), 
    GraphTest();
    ~GraphTest();

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