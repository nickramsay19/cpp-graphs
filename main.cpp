#include <iostream>
#include <string>

#include "Graph/Graph.hpp"
#include "Graph/Vertex/Vertex.hpp"
#include "Graph/Edge/Edge.hpp"

using namespace std;

bool istraversable(Vertex v1, Vertex v2, Edge* edges, int edges_length){

    // check if edges length is long enough
    if(edges_length < 1) return false;
    
    // create edges array of 1 less
    Edge other_edges[edges_length - 1];
    
    // find all vertices connected to v1
    for(int i = 0; i < edges_length; i++){
        
        // construct other_edges
        int dest_index = 0;
        for(int j = 0; j < edges_length; j++){
            
            if(j != i) {
                Vertex _v1 = Vertex(edges[j].v1.name);
                Vertex _v2 = Vertex(edges[j].v2.name);
                
                other_edges[dest_index++] = Edge(_v1, _v2);
            }
        }

        // find connected vertices across e_i
        if(edges[i].v1 == v1){ // v1 is connected to edges[i].v2
            
            // check if v2 has been found
            if(edges[i].v2 == v2) return true;
            
            // traverse from connected vertex
            if(istraversable(edges[i].v2, v2, other_edges, edges_length - 1)) return true;
            
        } else if(edges[i].v2 == v1){ // v1 is connected to edges[i].v1
            
            // check if v2 has been found
            if(edges[i].v1 == v2) return true;
                
            // traverse from connected vertex
            if(istraversable(edges[i].v1, v2, other_edges, edges_length - 1)) return true;
        }
    }
    
    // v2 has not been found
    return false;
}


int main(int argc, const char * argv[]) {

    Vertex vertices[] = {
        Vertex("v0"),
        Vertex("v1"),
        Vertex("v2"),
        Vertex("v3")
    };
    
    Edge edges[] = {
        Edge(Vertex("v0"), Vertex("v1")),
        Edge(Vertex("v1"), Vertex("v0")),
        Edge(Vertex("v2"), Vertex("v3"))
    };
    
    int vertices_length = sizeof(vertices) / sizeof(Vertex(""));
    int edges_length = sizeof(edges) / sizeof(Edge(Vertex(""), Vertex("")));
    
    Graph graph(vertices, edges, vertices_length, edges_length);
    
    
    bool is_traversable = istraversable(Vertex("v0"), Vertex("v3"), edges, edges_length);
    int degree_v0 = graph.degree(vertices[0]);
    
    
    cout << "deg(v0) : " << degree_v0 << endl;
    cout << "v0 -> v3 : " << (is_traversable ? "Yes" : "No") << endl;
    
    return 0;
}
