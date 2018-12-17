//
//  BellmanFord.h
//  BellmanFordAlgorithm
//
//  Created by Aleksander Konstantinov on 12/15/18.
//  Copyright © 2018 Oleksandr Konstantinov. All rights reserved.
//

#ifndef BellmanFord_h
#define BellmanFord_h

#include <vector>
#include "Vertex.h"
#include "Edge.h"
using namespace std;

class BellmanFord {
    
    vector<Vertex> &vertexList;
    vector<Edge> &edgeList;

public:
    BellmanFord(vector<Vertex> &_vertexList, vector<Edge> &_edgeList)
        : vertexList(_vertexList)
        , edgeList(_edgeList)
    {
    }
    
    void operator() (size_t sourceVertexIndex, size_t targetVertexIndex) const;
    
private:
    bool hasCycle(Edge const &edge) const;
};


#endif /* BellmanFord_h */
