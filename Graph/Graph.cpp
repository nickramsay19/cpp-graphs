#include "Graph.hpp"

#include <iostream>
#include <vector>
using namespace std;

Graph::Graph(vector<Vertex> _vertices, vector<Edge> _edges){
    vertices = _vertices;
    edges = _edges;
}

Graph::Graph(){
    vertices = vector<Vertex>();
    edges = vector<Edge>();
}

int Graph::degree(Vertex& v){
    
    long edges_length = edges.size();
    
    int total_degree = 0;
    
    for(int i = 0; i < edges_length; i++){
        if(edges[i].v1 == v) total_degree++;
        if(edges[i].v2 == v) total_degree++;
    }
    
    return total_degree;
}

bool Graph::istraversable(Vertex v1, Vertex v2){

    // get vector lengths
    //long vertices_length = vertices.size();
    long edges_length = edges.size();
    
    // check if edges length is long enough
    if(edges.size() < 1) return false;
    
    // create edges vector of 1 less for subgraph
    vector<Edge> other_edges;
    Graph subgraph;
    
    // find all vertices connected to v1
    for(int i = 0; i < edges_length; i++){
        
        // construct subgraph from edges drop e_i
        other_edges.clear();
        for(int j = 0; j < edges_length; j++){
            
            if(j != i) {
                Vertex _v1 = Vertex(edges[j].v1.name);
                Vertex _v2 = Vertex(edges[j].v2.name);
                
                other_edges.push_back(Edge(_v1, _v2));
            }
        }
        Graph subgraph(vertices, other_edges);
        

        // find connected vertices across e_i
        if(edges[i].v1 == v1){ // v1 is connected to edges[i].v2
            
            // check if v2 has been found
            if(edges[i].v2 == v2) return true;
            
            // traverse from connected vertex
            if(subgraph.istraversable(edges[i].v2, v2)) return true;
            //if(istraversable(edges[i].v2, v2, other_edges, edges_length - 1)) return true;
            
        } else if(edges[i].v2 == v1){ // v1 is connected to edges[i].v1
            
            // check if v2 has been found
            if(edges[i].v1 == v2) return true;
                
            // traverse from connected vertex
            if(subgraph.istraversable(edges[i].v1, v2)) return true;
            //if(istraversable(edges[i].v1, v2, other_edges, edges_length - 1)) return true;
        }
    }
    
    // v2 has not been found
    return false;
}

int Graph::traverse(Vertex v1, Vertex v2){

    // get vector lengths
    //long vertices_length = vertices.size();
    long edges_length = edges.size();
    
    // check if edges length is long enough
    if(edges.size() < 1) return -1;
    
    // create edges vector of 1 less for subgraph
    vector<Edge> other_edges;
    Graph subgraph;
    
    // find all vertices connected to v1
    for(int i = 0; i < edges_length; i++){
        
        // construct subgraph from edges drop e_i
        other_edges.clear();
        for(int j = 0; j < edges_length; j++){
            
            if(j != i) {
                Vertex _v1 = Vertex(edges[j].v1.name);
                Vertex _v2 = Vertex(edges[j].v2.name);
                
                other_edges.push_back(Edge(_v1, _v2));
            }
        }
        Graph subgraph(vertices, other_edges);
        

        // find connected vertices across e_i
        if(edges[i].v1 == v1){ // v1 is connected to edges[i].v2
            
            // check if v2 has been found
            if(edges[i].v2 == v2) return 1;
            
            // traverse from connected vertex
            int _v2_to_v2 = subgraph.traverse(edges[i].v2, v2);
            if(_v2_to_v2 != -1) return 1 + _v2_to_v2;
            //if(istraversable(edges[i].v2, v2, other_edges, edges_length - 1)) return true;
            
        } else if(edges[i].v2 == v1){ // v1 is connected to edges[i].v1
            
            // check if v2 has been found
            if(edges[i].v1 == v2) return 1;
                
            // traverse from connected vertex
            int _v1_to_v2 = subgraph.traverse(edges[i].v1, v2);
            if(_v1_to_v2 != -1) return 1 + _v1_to_v2;
            //if(istraversable(edges[i].v1, v2, other_edges, edges_length - 1)) return true;
        }
    }
    
    // v2 has not been found
    return -1;
}
