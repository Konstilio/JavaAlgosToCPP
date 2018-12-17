//
//  Vertex.cpp
//  BellmanFordAlgorithm
//
//  Created by Aleksander Konstantinov on 12/15/18.
//  Copyright © 2018 Oleksandr Konstantinov. All rights reserved.
//

#include "Vertex.h"

Vertex::Vertex(int id) {
    this->id = id;
}

int Vertex::getMinDistance() const {
    return minDistance;
}

void Vertex::setMinDistance(int minDistance) {
    this->minDistance = minDistance;
}

Vertex *Vertex::getPreviousVertex() const {
    return previousVertex;
}

void Vertex::setPreviousVertex(Vertex *previousVertex) {
    this->previousVertex = previousVertex;
}

bool Vertex::isVisited() const {
    return visited;
}

void Vertex::setVisited(bool visited) {
    this->visited = visited;
}

// to String
ostream &operator<<(ostream& strm, const Vertex &vertex)
{
    strm << vertex.id;
    return strm;
}
