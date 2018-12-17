//
//  main.cpp
//  Fibonacci
//
//  Created by Aleksander Konstantinov on 12/16/18.
//  Copyright © 2018 Oleksandr Konstantinov. All rights reserved.
//

#include <iostream>
#include "FibonacciAlgorithm.h"
using std::cout;

int main(int argc, const char * argv[]) {
    FibonacciAlgorithm fibonacciAlgorithm;
    cout << fibonacciAlgorithm.fibonacciMemorize(10) << '\n';
    cout << fibonacciAlgorithm.naiveFibonacci(10) << '\n';
    return 0;
}
