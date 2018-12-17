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
#include <list>
using std::vector;
using std::list;

class HashTable {
    
    static constexpr int TABLE_SIZE = 10;
    struct HashItem
    {
        int key = 0;
        int value = 0;
    };
    vector<list<HashItem>> hashTable;
    
public:
    
    HashTable();
    
    int get(int key);
    
    void put(int key, int value);
    
private:
    static int hash(int key);
};


#endif /* HashTable_hpp */
