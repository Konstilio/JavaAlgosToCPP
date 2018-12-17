//
//  HashTable.hpp
//  HashMapChaining
//
//  Created by Aleksander Konstantinov on 12/16/18.
//  Copyright © 2018 Oleksandr Konstantinov. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <vector>
#include <memory.h>
using std::vector;
using std::unique_ptr;
using std::make_unique;

class HashTable {
    
    static constexpr int TABLE_SIZE = 100;
    struct HashItem
    {
        int key = 0;
        int value = 0;
        
        // Constructor is neaded for make_unique funciton
        HashItem(int _key, int _val);
    };
    vector<unique_ptr<HashItem>> hashTable;
    
public:
    
    HashTable();
    
    int get(int key);    
    void put(int key, int value);
    
private:
    static int hash(int key);
};


#endif /* HashTable_hpp */
