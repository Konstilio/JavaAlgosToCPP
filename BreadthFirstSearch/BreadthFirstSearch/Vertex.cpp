//
//  Vertex.cpp
//  BellmanFordAlgorithm
//
//  Created by Aleksander Konstantinov on 12/15/18.
//  Copyright © 2018 Oleksandr Konstantinov. All rights reserved.
//

#include "Vertex.h"

Vertex::Vertex(int data) {
    this->data = data;
}

int Vertex::getData() const
{
    return data;
}

void Vertex::setData(int data)
{
    this->data = data;
}

bool Vertex::isVisited() const {
    return visited;
}

void Vertex::setVisited(bool visited) {
    this->visited = visited;
}

const vector<shared_ptr<Vertex>> &Vertex::getNeighbourList() const {
    return neighbours;
}

void Vertex::addNeighbour(const shared_ptr<Vertex> &neighbour)
{
    neighbours.push_back(neighbour);
}

// to String
ostream &operator<<(ostream& strm, const Vertex &vertex)
{
    strm << vertex.data;
    return strm;
}
