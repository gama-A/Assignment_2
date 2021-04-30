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

void HeapHash::heapify() {
    // stub
}

HeapHash::HeapHash(int K) {
    int prime;
    prime = smallestPrime(K);
    this->hash.resize(prime);
    this->heap.resize(K);
    this->heapSize = K;
    this->hashSize = prime;
}

HeapHash::~HeapHash() {
    // stub
}

void HeapHash::insert(string s) {
    int heapIndex, hashIndex;
    hashIndex = hash.findElement(s);
    if( hashIndex != -1 ) {
        heapIndex = (this->hash[hashIndex]).index_heap;
        (this->heap[heapIndex]).frequency += 1;
    }else {
        if( total_elements < this->heapSize ) {
            int age = this->counter;
            struct heapItem add(1,age,s);
            this->heap.push_back(add);
            // re order elements
            this->total_elements += 1;
        }
        else if( total_elements == this->heapSize ) {
            // stub
        }
    }
    // stub (updating indexes of heap items/hash indexes
    this->counter += 1;
}
