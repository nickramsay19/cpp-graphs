//
//  Edge.hpp
//  cpp-graphs
//
//  Created by Nick Ramsay on 9/4/20.
//  Copyright © 2020 Nick Ramsay. All rights reserved.
//

#ifndef Edge_hpp
#define Edge_hpp

#include <string>

#include "../Vertex/Vertex.hpp"

class Edge{
public:
    Vertex v1 = Vertex("");
    Vertex v2 = Vertex("");
    
    Edge(Vertex _v1 = Vertex(""), Vertex _v2 = Vertex(""));
    
    std::string ToString();
};

#endif /* Edge_hpp */
