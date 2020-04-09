//
//  Vertex.cpp
//  cpp-graphs
//
//  Created by Nick Ramsay on 9/4/20.
//  Copyright © 2020 Nick Ramsay. All rights reserved.
//

#include <string>

#include "Vertex.hpp"

Vertex::Vertex(std::string n){
    name = n;
}

bool Vertex::operator==(const Vertex& otherVertex){
    return name == otherVertex.name;
}
