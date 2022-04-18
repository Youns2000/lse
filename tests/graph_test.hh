#include <iostream>

using namespace std;

class GraphTest
{
public:
    GraphTest() = default;
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

    // GraphTest* props_reader(string file_path, string name);

    // friend std::ostream& operator<<(std::ostream& os, const GraphTest& g)
    // {
        
    //     return os;
    // }

    string path_;
    string name_;
    int nb_nodes_;
    int nb_edges_;
    bool is_directed_;
    bool is_connected_;
    float average_degree_;
    float average_weighted_degree_;
    int diameter_;
    float average_path_length_;
    float density_;
    float modularity_;

};

GraphTest props_reader(string file_path, string name)
{
    ifstream file_in(file_path);
    if (!file_in.is_open())
        throw ios_base::failure("Error opening file");

    GraphTest g;
    g.path_ = file_path;
    g.name_ = name;

    string nbn, nbe, diam , isd, isc, avg, avgw, avgp, dens, mod;

    while (file_in.good())
    {
        file_in >> nbn;
        g.nb_nodes_ = stoi(nbn);

        file_in >> nbe;
        g.nb_edges_ = stoi(nbe);

        file_in >> isd;
        g.is_directed_ = (isd == "True" ? true : false);

        file_in >> isc;
        g.is_connected_ = (isc == "True" ? true : false);

        // file_in >> avg;
        // g.average_degree_ = stof(avg);
        g.average_degree_ = 0.;

        file_in >> avgw;
        g.average_weighted_degree_ = stof(avgw);
        
        file_in >> diam;
        g.diameter_ = stof(diam);

        file_in >> avgp;
        g.average_path_length_ = stof(avgp);

        file_in >> dens;
        g.density_ = stof(dens);

        g.modularity_ = 0.;

        // file_in >> g.modularity_;
        // g.is_directed_ = stof(mod);
    }

    file_in.close();
    return g;
}