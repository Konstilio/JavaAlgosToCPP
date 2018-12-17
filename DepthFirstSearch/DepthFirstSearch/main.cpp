//
//  main.cpp
//  DepthFirstSearch
//
//  Created by Aleksander Konstantinov on 12/16/18.
//  Copyright © 2018 Oleksandr Konstantinov. All rights reserved.
//

#include <iostream>
#include "Vertex.h"
#include <memory.h>
#include "DepthFirstSearch.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<shared_ptr<Vertex>> graph;
    graph.resize(5);
    graph[0] = make_shared<Vertex>("1");
    graph[1] = make_shared<Vertex>("2");
    graph[2] = make_shared<Vertex>("3");
    graph[3] = make_shared<Vertex>("4");
    graph[4] = make_shared<Vertex>("5");
    
    graph[0]->addNeighbour(graph[1]);
    graph[0]->addNeighbour(graph[3]);
    graph[3]->addNeighbour(graph[4]);
    graph[1]->addNeighbour(graph[2]);
    
    DepthFirstSearch depthFirstSearch(graph);
    depthFirstSearch();
    depthFirstSearch.printVertices();
    
    return 0;
}
