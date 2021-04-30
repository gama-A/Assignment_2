// Gama Aristondo, 8404071
//
// Function definitions for "HeapHash.h"

#include <cmath>
#include <iostream>
#include <funtional>
#include <vector>
#include <string>
#include <math.h>

#include "HeapHash.h"

using namespace std;

bool HeapHash::isPrime(int n) {
    int root;
    root = (int)sqrt(n);
    if(root % 2 == 0) return true;
    for(int i = 3; i <= root; i += 2) {
        if(root % i == 0) return false;
    }
    return true;
}

int HeapHash::smallestPrime(int K) {
    K = 2*K;
    while(!isPrime(K)) {
        K++;
    }
    return K;
}

int HeapHash::findElement(string s) {
    hash<string> element;
    unsigned int i = element(s);
    int M = this->hashSize;
    int index, initialIndex;
    initialIndex = i % M;
    for(int x = 0; x < M/2; x++) {
        index = (int)(initialIndex + pow(x,2));
        if(index >= M) {
            index = index - M;
        }
        else if(index == initialIndex) {
            break;
        }
        else if( (this->hash[index]).s == s ) {
            return index;
        }
    }
    return -1;
}

int HeapHash::deleteMin() {
    int frequency = (this->heap[0]).frequency;
    string item = (this->heap[0]).s;
    int hashIndex = this->findElement(item);
    
    return frequency;
}

void HeapHash::reoraginzeStructure() {
    // stub
}

HeapHash::HeapHash(int K) {
    int prime;
    prime = smallestPrime(K);
    struct heapItem initial_HeapValues(0,0,"");
    struct hashItem initial_HashValues("",0);
    this->hash.resize(prime,initial_HashValues);
    this->heap.resize(K,initial_HeapValues);
    this->heapSize = K;
    this->hashSize = prime;
}

HeapHash::~HeapHash() {
    // stub
}

void HeapHash::insert(string s) {
    int heapIndex, hashIndex, age;
    hashIndex = this->findElement(s);
    if( hashIndex != -1 ) {
        heapIndex = (this->hash[hashIndex]).index_heap;
        (this->heap[heapIndex]).frequency += 1;
    }else {
        age = this->counter;
        if( total_elements < this->heapSize ) {
            struct heapItem add(1,age,s);
            this->heap.push_back(add);
            this->total_elements += 1;
        }
        else if( total_elements == this->heapSize ) {
            int freq = this->deleteMin();
            struct heapItem add(freq+1,age,s);
            this->heap.push_back(add);
        }
    }
    this->reorganizeStructure();
    this->counter += 1;
}
