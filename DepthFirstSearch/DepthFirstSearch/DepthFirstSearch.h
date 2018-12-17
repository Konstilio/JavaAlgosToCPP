//
//  DepthFirstSearch.h
//  DepthFirstSearch
//
//  Created by Aleksander Konstantinov on 12/16/18.
//  Copyright © 2018 Oleksandr Konstantinov. All rights reserved.
//

#ifndef DepthFirstSearch_h
#define DepthFirstSearch_h

#include "Vertex.h"
#include <vector>
#include <memory.h>
#include <iostream>
using std::vector;
using std::shared_ptr;
using std::cout;

class DepthFirstSearch {
    
    vector<shared_ptr<Vertex>> vertexList;
    int time = 0;
    
public:
    DepthFirstSearch(vector<shared_ptr<Vertex>> const &_vertexList);
    void operator()();
    void printVertices() const;
    
private:
    void dfs(shared_ptr<Vertex> vertex);
};


#endif /* DepthFirstSearch_h */
