//
//  BreadthFirstSearch.h
//  BreadthFirstSearch
//
//  Created by Aleksander Konstantinov on 12/15/18.
//  Copyright © 2018 Oleksandr Konstantinov. All rights reserved.
//

#ifndef BreadthFirstSearch_h
#define BreadthFirstSearch_h

#include "Vertex.h"
#include <deque>
#include <iostream>

class BreadthFirstSearch {
    
public:
    void operator()(shared_ptr<Vertex> root) const;
};

#endif /* BreadthFirstSearch_h */
