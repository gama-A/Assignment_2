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
    K += 1;
    while(!isPrime(K)) {
        K++;
    }
    return K;
}

HeapHash::HeapHash(int K) {
    int prime;
    prime = smallestPrime(K);
    hash.resize(prime);
    this->sizeHeap = K;
    this->sizeHash = prime;
}

HeapHash::~HeapHash() {
    // stub
}

void HeapHash::insert(string s) {
    hash<string> element;
    unsigned int i = element(s);
    if( (hash[i % this->sizeHash]).first == s ) {
        incrementFrequency(s);
    }else {
        if( hash.
    // stub
}
