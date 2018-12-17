//
//  Vertex.hpp
//  BellmanFordAlgorithm
//
//  Created by Aleksander Konstantinov on 12/15/18.
//  Copyright © 2018 Oleksandr Konstantinov. All rights reserved.
//

#ifndef Vertex_h
#define Vertex_h

#include <vector>
#include <ostream>
using namespace std;

class Vertex {

private:
    
    int data = 0;
    bool visited = false;
    vector<Vertex *> neighbours;
    
public:
    Vertex(int data);
	~Vertex();
    
    int getData() const;
    void setData(int data);
    
    bool isVisited() const;
    void setVisited(bool visited);
    
    const vector<Vertex *> &getNeighbourList() const;
    void addNeighbour(Vertex *neighbour);
    
    friend ostream &operator<<(ostream &os, const Vertex &vertex);
};

#endif /* Vertex_hpp */
