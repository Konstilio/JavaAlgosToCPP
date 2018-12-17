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
#include <string>
using namespace std;

class Vertex {

private:
    
    string name = 0;
    bool visited = false;
    vector<Vertex *> neighbours;
    int startingRank = -1;
    int finishingRank = -1;
    
public:
    Vertex(const string &name);
    ~Vertex();
    
    const string &getName() const;
    void setName(const string &name);
    
    bool isVisited() const;
    void setVisited(bool visited);
    
    const vector<Vertex *> &getNeighbourList() const;
    void addNeighbour(Vertex *neighbour);
    
    void setStartingRank(int startingRank);
    int getStartingRank() const;
    
    void setFinishingRank(int finishingRank);
    int getFinishingRank() const;
    
    friend ostream &operator<<(ostream &os, const Vertex &vertex);
};

#endif /* Vertex_hpp */
