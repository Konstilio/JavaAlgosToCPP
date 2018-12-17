//
//  main.cpp
//  BellmanFordAlgorithm
//

#include <iostream>

#include "Vertex.h"
#include "Edge.h"
#include "BellmanFord.h"

int main(int argc, const char * argv[]) {
    
    vector<Vertex> vertexList;
    
    vertexList.push_back(Vertex(1));
    vertexList.push_back(Vertex(2));
    vertexList.push_back(Vertex(3));
    vertexList.push_back(Vertex(4));
    vertexList.push_back(Vertex(5));
    
    vector<Edge> edgeList;
    edgeList.push_back(Edge(&vertexList[0], &vertexList[1], 5));
    edgeList.push_back(Edge(&vertexList[0], &vertexList[3], -4));
    edgeList.push_back(Edge(&vertexList[0], &vertexList[2], 8));
    edgeList.push_back(Edge(&vertexList[1], &vertexList[0], -2));
    edgeList.push_back(Edge(&vertexList[2], &vertexList[1], -3));
    edgeList.push_back(Edge(&vertexList[2], &vertexList[3], 9));
    edgeList.push_back(Edge(&vertexList[3], &vertexList[1], 7));
    edgeList.push_back(Edge(&vertexList[4], &vertexList[0], 6));
    edgeList.push_back(Edge(&vertexList[4], &vertexList[2], 7));
    
    BellmanFord bellmannFordAlgorithm = BellmanFord(vertexList,edgeList);
    bellmannFordAlgorithm(4, 3);
	std::cin.get();
    return 0;
}
