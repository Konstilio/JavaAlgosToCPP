//
//  HashTable.cpp
//  HashMapChaining
//
//  Created by Aleksander Konstantinov on 12/16/18.
//  Copyright © 2018 Oleksandr Konstantinov. All rights reserved.
//

#include "HashTable.h"
#include <iostream>
using std::cout;

HashTable::HashTable() {
    hashTable.resize(TABLE_SIZE);
}

int HashTable::get(int key) {
    
    int generatedArrayIndex = hash(key);
    
    list<HashItem> &items = hashTable[generatedArrayIndex];
    if( hashTable[generatedArrayIndex].empty())
        return -1;
    
    for (HashItem const &item : items)
    {
        if (item.key == key)
            return item.value;
    }
    
    return -1;
}

void HashTable::put(int key, int value) {
    
    int hashArrayIndex = hash(key);
    list<HashItem> &items = hashTable[hashArrayIndex];
    
    if( items.empty() ) {
        cout << "No collision simple insertion...\n";
    } else {
        
        cout << "Collision when inserting with key " << key << '\n';
        for (HashItem const &item : items)
        {
            if (item.key == key)
            {
                cout << "item is already inserted...\n";
                return;
            }
        }
    }
    
    items.push_back(HashItem{key, value});
}

int HashTable::hash(int key) {
    return key % TABLE_SIZE;
}
