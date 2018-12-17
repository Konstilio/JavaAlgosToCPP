//
//  FibonacciAlgorithm.cpp
//  Fibonacci
//
//  Created by Aleksander Konstantinov on 12/16/18.
//  Copyright © 2018 Oleksandr Konstantinov. All rights reserved.
//

#include "FibonacciAlgorithm.h"

FibonacciAlgorithm::FibonacciAlgorithm()
{
    memorizeTable.resize(2);
    memorizeTable[0] = 0;
    memorizeTable[1] = 1;
}

int FibonacciAlgorithm::fibonacciMemorize(int n)
{
    if (memorizeTable.size() >= n + 1)
        return memorizeTable[n];
    
    size_t oldSize = memorizeTable.size();
    memorizeTable.resize(n + 1);
    for (size_t i = oldSize; i <= n; ++i)
        memorizeTable[i] = memorizeTable[i - 2] + memorizeTable[i - 1];
    
    return memorizeTable[n];
    
}

int FibonacciAlgorithm::naiveFibonacci(int n)
{
    
    if( n == 0 ) return 0;
    if( n == 1 ) return 1;
    
    return naiveFibonacci(n-1) + naiveFibonacci(n-2);
}
