//
//  generic_heap.hpp
//  structures-algorithms
//
//  Created by Vadym Sidorov on 2/21/17.
//  Copyright © 2017 Vadym Sidorov. All rights reserved.
//

#ifndef generic_heap_hpp
#define generic_heap_hpp

#include <vector>
#include <algorithm>

#define HEAP_HEAD 0

namespace StudyStructures {

template <typename T>
class Heap {
public:
    Heap() = default;
    
    bool isEmpty();
    void push(T newElement);
    void pop();
    
    void print() const;
    
private:
    void heapify(int id);
    
    std::vector<T> data;
};

template <typename T>
bool Heap<T>::isEmpty() {
    return data.empty();
}

template <typename T>
void Heap<T>::push(T newElement) {
    data.push_back(newElement);
    int elementId = static_cast<int>((data.size() - 1));
    while (data[elementId] < data[elementId / 2]) {
        std::iter_swap(data.begin() + elementId, data.begin() + elementId / 2);
        elementId /= 2;
    }
}

template <typename T>
void Heap<T>::pop() {
    if (isEmpty()) return;
    
    std::iter_swap(data.begin(), data.end() - 1);
    data.pop_back();
    heapify(HEAP_HEAD);
}

template <typename T>
void Heap<T>::print() const {
    int prevLineBreakId = 0;
    
    for (typename std::vector<T>::const_iterator it = data.begin(); it != data.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void Heap<T>::heapify(int id) {
    int minChildId;
    const int leftChildId = id * 2 + 1;
    const int rightChildId = id * 2 + 2;
    
    // no children
    if (leftChildId > data.size() - 1) { return; }
    
    // one child
    if (rightChildId > data.size()) {
        minChildId = leftChildId;
    } else { // two children, minimum selected
        minChildId = (data[leftChildId] <= data[rightChildId]) ? leftChildId : rightChildId;
    }
    
    if (data[id] > data[minChildId]) {
        std::iter_swap(data.begin() + minChildId, data.begin() + id);
        heapify(minChildId);
    }
}
    
}


#endif /* generic_heap_hpp */
