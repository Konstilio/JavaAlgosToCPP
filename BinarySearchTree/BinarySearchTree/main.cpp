//
//  main.cpp
//  BinarySearchTree
//
//  Created by Aleksander Konstantinov on 12/16/18.
//  Copyright © 2018 Oleksandr Konstantinov. All rights reserved.
//

#include <iostream>
#include "BinarySearchTree.h"
#include "Person.h"

int main(int argc, const char * argv[]) {
    std::shared_ptr<Tree<Person>> bst = std::make_shared<BinarySearchTree<Person>>();
    
    bst->insert(Person("Adam",27));
    bst->insert(Person("Kevin",13));
    bst->insert(Person("Joe",67));
    bst->insert(Person("Michael",2));
    bst->insert(Person("Smith",11));
    
    bst->traversal();
	std::cin.get();
    return 0;
}
