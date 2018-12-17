//
//  Knapsack.cpp
//  KnapsackProblem
//
//  Created by Aleksander Konstantinov on 12/16/18.
//  Copyright © 2018 Oleksandr Konstantinov. All rights reserved.
//

#include "Knapsack.h"
#include <algorithm>
#include <iostream>

Knapsack::Knapsack(int _numOfItems, int _capacityOfKnapsack, const vector<int> &_weights, const vector<int> &_values)
    : numOfItems(_numOfItems)
    , capacityOfKnapsack(_capacityOfKnapsack)
    , weights(_weights)
    , values(_values)
{
    knapsackTable.resize(numOfItems + 1);
    for (auto &item : knapsackTable)
        item.resize(capacityOfKnapsack + 1);
}

void Knapsack::operator()() {
    
    // time complexity: O(N*W)
    for(int i=1; i<numOfItems + 1; ++i) {
        for(int w = 1; w < capacityOfKnapsack + 1; ++w) {
            
            int notTakingItem = knapsackTable[i-1][w]; // not taking item i
            
            int takingItem = 0;
            if( weights[i] <= w ) {
                takingItem = values[i] + knapsackTable[i-1][w-weights[i]];
            }
            
            knapsackTable[i][w] = std::max(notTakingItem, takingItem);
        }
    }
    
    totalBenefit = knapsackTable[numOfItems][capacityOfKnapsack];
}

void Knapsack::showResult() {
    
    std::cout << "Total benefit: " << totalBenefit << '\n';
    
    for(int n=numOfItems, w = capacityOfKnapsack; n > 0; --n) {
        if( knapsackTable[n][w] != 0 && knapsackTable[n][w] != knapsackTable[n-1][w] ) {
            std::cout << "We take item: #" << n << '\n';
            w = w - weights[n];
        }
    }
}
