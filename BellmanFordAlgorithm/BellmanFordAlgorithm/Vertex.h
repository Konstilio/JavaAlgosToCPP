//
//  Vertex.hpp
//  BellmanFordAlgorithm
//
//  Created by Aleksander Konstantinov on 12/15/18.
//  Copyright © 2018 Oleksandr Konstantinov. All rights reserved.
//

#ifndef Vertex_h
#define Vertex_h

#include "Edge.h"
#include <vector>
#include <ostream>
using namespace std;

class Vertex {

private:
    
    int id;
    bool visited;
    int minDistance = INT_MAX;
    Vertex *previousVertex = nullptr;
    
public:
    Vertex(int id);
    
    int getMinDistance() const;
    
    void setMinDistance(int minDistance);
    
    Vertex *getPreviousVertex() const;
        
    void setPreviousVertex(Vertex *previousVertex);
    
    bool isVisited() const;
    
    void setVisited(bool visited);
    
    friend ostream &operator<<(ostream &os, const Vertex &vertex);
};

#endif /* Vertex_hpp */
