//
//  DepthFirstSearch.cpp
//  DepthFirstSearch
//
//  Created by Aleksander Konstantinov on 12/16/18.
//  Copyright © 2018 Oleksandr Konstantinov. All rights reserved.
//

#include "DepthFirstSearch.h"

DepthFirstSearch::DepthFirstSearch(vector<shared_ptr<Vertex>> const &_vertexList)
    : vertexList(_vertexList)
{
}

void DepthFirstSearch::operator()()
{
    for (auto vertex : vertexList )
    {
        if(!vertex->isVisited() )
            dfs(vertex.get());
    }
    cout << '\n';
}

void DepthFirstSearch::dfs(Vertex *vertex){
    
    cout << vertex->getName() << "-";
    
    time++;
    vertex->setStartingRank(time);
    
    for(Vertex *v : vertex->getNeighbourList() ){
        if(!v->isVisited() ){
            v->setVisited(true);
            dfs(v);
        }
    }
    
    time++;
    vertex->setFinishingRank(time);
}

void DepthFirstSearch::printVertices() const
{
    for(auto vertex : vertexList)
    {
        cout << *vertex << '\n';
    }
}
