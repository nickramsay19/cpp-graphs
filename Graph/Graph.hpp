#ifndef Graph_hpp
#define Graph_hpp

#include <vector>

#include "Vertex/Vertex.hpp"
#include "Edge/Edge.hpp"

using namespace std;

class Graph {
public:

    vector<Vertex> vertices;
    vector<Edge> edges;
    
    Graph(vector<Vertex> _vertices, vector<Edge> _edges);
    Graph();
    
    int degree(Vertex& v);
    
    bool istraversable(Vertex v1, Vertex v2);
    
    int traverse(Vertex v1, Vertex v2);
};

#endif /* Graph_hpp */
