//
//  Vertex.hpp
//  cpp-graphs
//
//  Created by Nick Ramsay on 9/4/20.
//  Copyright © 2020 Nick Ramsay. All rights reserved.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include <string>

class Vertex{
public:
    std::string name = "";
    
    Vertex(std::string n = "");
    
    bool operator==(const Vertex& otherVertex);
};

#endif /* Vertex_hpp */
