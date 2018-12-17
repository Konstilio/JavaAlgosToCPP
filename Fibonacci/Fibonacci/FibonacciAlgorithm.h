//
//  FibonacciAlgorithm.h
//  Fibonacci
//
//  Created by Aleksander Konstantinov on 12/16/18.
//  Copyright © 2018 Oleksandr Konstantinov. All rights reserved.
//

#ifndef FibonacciAlgorithm_h
#define FibonacciAlgorithm_h

#include <vector>
using std::vector;


class FibonacciAlgorithm {
    vector<int> memorizeTable; // O(1)
    
public:
    
    FibonacciAlgorithm();
    
    int fibonacciMemorize(int n);
    int naiveFibonacci(int n);
};


#endif /* FibonacciAlgorithm_h */
