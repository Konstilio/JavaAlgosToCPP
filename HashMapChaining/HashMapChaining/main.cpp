//
//  main.cpp
//  HashMapChaining
//
//  Created by Aleksander Konstantinov on 12/16/18.
//  Copyright © 2018 Oleksandr Konstantinov. All rights reserved.
//

#include "HashTable.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    HashTable hashTable {};
    
    for (int i = 1; i <= 30; ++i)
        hashTable.put(i, i * 10);

    // duplicate insertion (shouldn't do anything)
    for (int i = 1; i <= 5; ++i)
        hashTable.put(i, i * 10);
    
    for (int i = 0; i <= 30; ++i)
        std::cout << hashTable.get(i) << ' ';
    
    return 0;
}
