//
//  GraphColoring.cpp
//  ColoringProblem
//
//  Created by Aleksander Konstantinov on 12/16/18.
//  Copyright © 2018 Oleksandr Konstantinov. All rights reserved.
//

#include "GraphColoring.h"
#include <iostream>
using namespace std;

GraphColoring::GraphColoring(const vector<vector<int>> &graph, int _numOfColors)
    : graphMatrix(graph)
    , numOfColors(_numOfColors)
{
    colors.resize(graphMatrix.size());
}

void GraphColoring::operator()()
{
    
    if( solve(0) ) {
        showResult();
    } else {
        cout << "No solution with the given parameters...\n";
    }
}

/** function to assign colors recursively **/
bool GraphColoring::solve(size_t nodeIndex)
{
    if (nodeIndex == graphMatrix.size()) {
        return true;
    }
    
    /** try all colours **/
    for (int colorIndex = 1; colorIndex <= numOfColors; colorIndex++) {
        if (isColorValid(nodeIndex, colorIndex)) {
            /** assign and proceed with next vertex **/
            colors[nodeIndex] = colorIndex;
            if( solve(nodeIndex + 1) )
                return true;
        }
    }
    
    return false;
}

/** function to check if it is valid to allot that color to vertex **/
bool GraphColoring::isColorValid(size_t nodeInex, size_t colorInedex) {
    for (size_t i = 0; i < graphMatrix.size(); i++) {
        if (graphMatrix[nodeInex][i] == 1 && colorInedex == colors[i]) {
            return false;
        }
    }
    
    return true;
}

void GraphColoring::showResult() {
    for (size_t i = 0; i < graphMatrix.size(); i++)
       cout << "Node " << (i + 1) << " has color index: " << colors[i] << "\n";
    cout << '\n';
    
}
