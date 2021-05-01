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
    int freq = (this->heap[0]).frequency;
    string item = (this->heap[0]).s;
    int hashIndex = this->findElement(item);
    struct heapItem nullHeap_Item(0,0,"");
    struct hashItem nullHash_Item("",0);
    this->heap[0] = nullHeap_Item;
    this->hash[hashIndex] = nullHash_Item;
    return freq;
}

void HeapHash::newHashItem(string s, int index) {
    struct hashItem add(s,index);
    hash<string> element;
    unsigned int i = element(s);
    int M = this->hashSize;
    int initialIndex = i % M;
    int in;
    for(int x = 0; x < M/2; x++) {
        in = (int)(initialIndex + pow(x,2));
        if(in >= M) {
            in = in - M;
        }
        else if( (this->hash[in]).s == "" ) {
            this->hash[in] = add;
        }
    }
}

void HeapHash::reoraginzeStructure() {
    int t = this->total_elements;
    for(int i = 0; i < t; i++)
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
    int heapIndex, hashIndex, age, total;
    hashIndex = this->findElement(s);
    if( hashIndex != -1 ) {
        heapIndex = (this->hash[hashIndex]).index_heap;
        (this->heap[heapIndex]).frequency += 1;
    }else {
        age = this->counter;
        total = this->total_elements;
        if( total < this->heapSize ) {
            struct heapItem add(1,age,s);
            this->heap[total] = add;
            this->total_elements += 1;
            this->newHashItem(s,total+1);
        }
        else if( total_elements == this->heapSize ) {
            int freq = this->deleteMin();
            struct heapItem add(freq+1,age,s);
            this->heap[0] = add;
            this->newHashItem(s,0);
        }
    }
    this->reorganizeStructure();
    this->counter += 1;
}
