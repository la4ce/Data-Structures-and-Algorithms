//
//  main.cpp
//  structures-algorithms
//
//  Created by Vadym Sidorov on 2/21/17.
//  Copyright © 2017 Vadym Sidorov. All rights reserved.
//

#include <iostream>
#include "generic_heap.hpp"

using namespace StudyStructures;

int main(int argc, const char *argv[]) {
    Heap<int> intHeap;
    intHeap.push(1);
    intHeap.push(10);
    intHeap.push(2);
    intHeap.push(1);
    intHeap.push(-1);
    intHeap.push(6);
    intHeap.push(0);
    
    intHeap.print();
    
    intHeap.pop();
    
    intHeap.print();
    
    intHeap.push(-1);
    intHeap.push(6);
    intHeap.push(0);
    
    intHeap.print();
    
    return 0;
}
