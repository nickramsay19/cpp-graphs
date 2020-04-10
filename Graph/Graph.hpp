//
//  Graph.hpp
//  cpp-graphs
//
//  Created by Nick Ramsay on 10/4/20.
//  Copyright © 2020 Nick Ramsay. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include "Vertex/Vertex.hpp"
#include "Edge/Edge.hpp"

class Graph {
public:

    Vertex* vertices;
    Edge* edges;
    
    Graph(Vertex _vertices[], Edge _edges[], int vertices_length, int edges_length){
        vertices = _vertices;
        edges = _edges;
    }
    
    int degree(Vertex& v){
        
        int edges_length = get_edges_length();
        
        int total_degree = 0;
        
        for(int i = 0; i < edges_length; i++){
            if(edges[i].v1 == v) total_degree++;
            if(edges[i].v2 == v) total_degree++;
        }
        
        return total_degree;
    }
private:
    int get_vertices_length(){
        return sizeof(*vertices) / sizeof(Vertex(""));
    }
    int get_edges_length(){
        return sizeof(*edges) / sizeof(Edge(Vertex(""), Vertex("")));
    }

};

#endif /* Graph_hpp */
