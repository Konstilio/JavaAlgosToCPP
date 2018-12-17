//
//  Edge.cpp
//  BellmanFordAlgorithm
//
//  Created by Aleksander Konstantinov on 12/15/18.
//  Copyright © 2018 Oleksandr Konstantinov. All rights reserved.
//

#include "Edge.h"

Edge::Edge(Vertex *startVertex, Vertex *targetVertex, int weight) {
    this->weight = weight;
    this->startVertex = startVertex;
    this->targetVertex = targetVertex;
}

int Edge::getWeight() const {
    return weight;
}

void Edge::setWeight(int weight) {
    this->weight = weight;
}

Vertex *Edge::getStartVertex() const {
    return startVertex;
}

void Edge::setStartVertex(Vertex *startVertex) {
    this->startVertex = startVertex;
}

Vertex *Edge::getTargetVertex() const {
    return targetVertex;
}

void Edge::setTargetVertex(Vertex *targetVertex) {
    this->targetVertex = targetVertex;
}

