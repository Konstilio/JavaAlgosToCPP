//
//  Vertex.cpp
//  BellmanFordAlgorithm
//
//  Created by Aleksander Konstantinov on 12/15/18.
//  Copyright © 2018 Oleksandr Konstantinov. All rights reserved.
//

#include "Vertex.h"

Vertex::Vertex(const string &_name)
   :name(_name)
{
}

Vertex::~Vertex() = default;

const string &Vertex::getName() const
{
    return name;
}

void Vertex::setName(const string &name)
{
    this->name = name;
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

void Vertex::setStartingRank(int startingRank)
{
    this->startingRank = startingRank;
}

int Vertex::getStartingRank() const
{
    return startingRank;
}

void Vertex::setFinishingRank(int finishingRank)
{
    this->finishingRank = finishingRank;
}

int Vertex::getFinishingRank() const
{
    return finishingRank;
}

// to String
ostream &operator<<(ostream& strm, const Vertex &vertex)
{
    strm << vertex.name << " Start time: " << vertex.startingRank << " - End time: " << vertex.finishingRank << '\n';
    return strm;
}
