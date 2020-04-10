//
//  Edge.cpp
//  cpp-graphs
//
//  Created by Nick Ramsay on 9/4/20.
//  Copyright © 2020 Nick Ramsay. All rights reserved.
//

#include "Edge.hpp"

#include "../Vertex/Vertex.hpp"

Edge::Edge(Vertex _v1, Vertex _v2){
    v1 = _v1;
    v2 = _v2;
}

std::string Edge::ToString(){
    return v1.name + " <-> " + v2.name;
}
