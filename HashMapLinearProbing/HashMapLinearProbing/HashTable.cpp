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

HashTable::HashItem::HashItem(int _key, int _val)
    : key(_key)
    , value(_val)
{
}

int HashTable::get(int key) {
    
    int generatedIndex = hash(key) % TABLE_SIZE;
    
    while( hashTable[generatedIndex] != nullptr && hashTable[generatedIndex]->key != key ) {
        generatedIndex = (generatedIndex+1) % TABLE_SIZE;
        cout << "Hopping to the next index: " << generatedIndex << '\n';
    }
    
    if( hashTable[generatedIndex] == nullptr )
        return -1;
    
    return hashTable[generatedIndex]->value;
}

// #TODO: Linear probing HashMap will not work properly without loading factor and increasing
void HashTable::put(int key, int value) {
    
    int generatedIndex = hash(key) % TABLE_SIZE;
    cout << "put() method called with value: " << value <<  " - generatedIndex: " << generatedIndex << '\n';
    
    // #TODO: this loop will never end in case hashTable size equals to TABLE_SIZE
    while( hashTable[generatedIndex] != nullptr ) {
        if (hashTable[generatedIndex]->key == key)
        {
            cout << "item is already exists...\n";
            return;
        }
        
        generatedIndex = (generatedIndex + 1) % TABLE_SIZE;
        cout << "Collision -> nexIndex: " << generatedIndex << '\n';
    }
    
    cout << "Inserted finally with index: " << generatedIndex << '\n';
    hashTable[generatedIndex] = make_unique<HashItem>(key, value);
}

int HashTable::hash(int key) {
    return key;
}
