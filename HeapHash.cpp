// Gama Aristondo, 8404071
//
// Function definitions for "HeapHash.h"

#include <cmath>
#include <iostream>
#include <vector>
#include <utility>
#include <hash>
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
        K += 1;
    }
    return K;
}

HeapHash::HeapHash(int K) {
    int prime;
    prime = smallestPrime(K);
    hash.resize(prime);
}

HeapHash::~HeapHash() {
    // stub
}

void HeapHash::insert(std::string s) {
    // stub
}
