// Gama Aristondo, 8404071
//
// Function definitions for "HeapHash.h"

#include <cmath>
#include <iostream>
#include <funtional>
#include <vector>
#include <utility>
#include <string>

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

HeapHash::HeapHash(int K) {
    int prime;
    prime = smallestPrime(K);
    hash.resize(prime);
    heap.resize(K);
    this->heapSize = K;
    this->hashSize = prime;
}

HeapHash::~HeapHash() {
    // stub
}

void HeapHash::insert(string s) {
    int hashIndex, heapIndex;
    hash<string> element;
    unsigned int i = element(s);
    bool status = hash.chechIfElementExists(s);
    if( status ) {
        // stub
    }else {
        if( total_elements < this->heapSize ) {
            // stub
        }
        else if( total_elements == this->heapSize ) {
            // stub
        }
    }
}
