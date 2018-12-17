//
//  BreadthFirstSearch.cpp
//  BreadthFirstSearch
//
//  Created by Aleksander Konstantinov on 12/15/18.
//  Copyright © 2018 Oleksandr Konstantinov. All rights reserved.
//

#include "BreadthFirstSearch.h"

void BreadthFirstSearch::operator()(shared_ptr<Vertex> root) const {
    
    std::deque<shared_ptr<Vertex>> queue;
    root->setVisited(true);
    queue.push_back(root);
    
    while(!queue.empty()){
        
        shared_ptr<Vertex> actualVertex = queue.front();
        queue.pop_front();
        cout << *actualVertex << ' ';
        
        for(shared_ptr<Vertex> v : actualVertex->getNeighbourList() ){
            if(!v->isVisited() ){
                v->setVisited(true);
                queue.push_back(v);
            }
        }
    }
}
