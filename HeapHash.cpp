// Gama Aristondo, 8404071
//
// Function definitions for "HeapHash.h"

#include <cmath>
#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <math.h>
#include <sstream>

#include "HeapHash.h"

using namespace std;

bool HeapHash::isPrime(int n) {
    int root = sqrt(n);
    for(int i = 2; i <= root; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int HeapHash::smallestPrime(int K) {
    K = 2*K;
    do {
        K++;
    }while(!isPrime(K));
    return K;
}

int HeapHash::findElement(string s) {
    hash<string> str_hash;
    unsigned int i = str_hash(s);
    int M = this->hashSize;
    int index, initialIndex;
    initialIndex = i % M;
    for(int x = 0; x < M/2; x++) {
        index = (int)(initialIndex + pow(x,2)) % M;
        if( (this->Hash[index]).item == s ) {
            return index;
        }
    }
    return -1;
}

int HeapHash::minFreq() {
    int freq = (this->Heap[0]).frequency;
    int hashIndex = (this->Heap[0]).index_hash;
    (this->Hash[hashIndex]).item = "deleted_item";
    return freq;
}

int HeapHash::newHashItem(string s, int index) {
    struct hashItem add;
    add.item = s;
    add.index_heap = index;
    hash<string> str_hash;
    unsigned int i = str_hash(s);
    int M = this->hashSize;
    int initialIndex = i % M;
    int in;
    for(int x = 0; x < M/2; x++) {
        in = (int)(initialIndex + pow(x,2)) % M;
        if( (this->Hash[in]).item == "" && (this->Hash[in]).index_heap == 0 ) {
            this->Hash[in] = add;
            break;
        }
        else if( (this->Hash[in]).item == "deleted_item" ) {
            this->Hash[in] = add;
            break;
        }
    }
    return in;
}

void HeapHash::heapSort() {
    int t = this->total_elements;
    for(int i = t/2 - 1; i >= 0; i--) {
        this->heapify(i);
    }
    for(int j = 0; j < t-1; j++) {
        this->checkNodes(j,j+1);
    }
    for(int k = 0; k < t; k++) {
        this->checkHash(k);
    }
}

void HeapHash::swapNodes(int index_1, int index_2) {
    struct heapItem temp = this->Heap[index_1];
    this->Heap[index_1] = this->Heap[index_2];
    this->Heap[index_2] = temp;
    this->updateHash(index_1);
    this->updateHash(index_2);
}

void HeapHash::checkHash(int index) {
    int hash_index = (this->Heap[index]).index_hash;
    if( (this->Hash[hash_index]).index_heap != index ) {
        updateHash(index);
    }
}

void HeapHash::checkNodes(int index_1, int index_2) {
    if( (this->Heap[index_1]).frequency > (this->Heap[index_2]).frequency ) {
        this->swapNodes(index_1, index_2);
    }
    else if( (this->Heap[index_1]).frequency == (this->Heap[index_2]).frequency ) {
        int c = breakTie(index_1,index_2);
        if( c == index_2 ) {
            this->swapNodes(index_1, index_2);
        }
    }
}

void HeapHash::heapify(int i) {
    int child = (2*i) + 1;
    struct heapItem temp = this->Heap[i];
    int total = this->total_elements;
    while(child < total) {
        if(child+1 < total) {
            this->checkNodes(child,child+1);
        }
        if( temp.frequency < (this->Heap[child]).frequency ) {
            break;
        }
        else if( temp.frequency == (this->Heap[child]).frequency ) {
            int b = breakTie(i,child);
            if(b == i) {
                break;
            }
        }
        this->Heap[i] = this->Heap[child];
        i = child;
        child = 2*child + 1;
    }
    this->Heap[i] = temp;
}

int HeapHash::breakTie(int index_1, int index_2) {
    struct heapItem temp1 = this->Heap[index_1];
    struct heapItem temp2 = this->Heap[index_2];
    if(temp1.age > temp2.age) {
        return index_1;
    }
    return index_2;
}

void HeapHash::updateHash(int index) {
    int h_index = (this->Heap[index]).index_hash;
    (this->Hash[h_index]).index_heap = index;
}

HeapHash::HeapHash(int K) {
    this->Heap.resize(K);
    this->heapSize = K;
    int prime;
    prime = smallestPrime(K);
    this->Hash.resize(prime);
    this->hashSize = prime;
    this->total_elements = 0;
    this->counter = 0;
}

HeapHash::~HeapHash() {}

void HeapHash::insert(string s) {
    int heapIndex, hashIndex, age, total;
    hashIndex = this->findElement(s);
    if( hashIndex != -1 ) {
        heapIndex = (this->Hash[hashIndex]).index_heap;
        (this->Heap[heapIndex]).frequency += 1;
    }else {
        age = this->counter;
        total = this->total_elements;
        struct heapItem add;
        add.age = age;
        add.item = s;
        if( total < this->heapSize ) {
            add.frequency = 1;
            int i_hash = newHashItem(s,total);
            add.index_hash = i_hash;
            this->Heap[total] = add;
            this->total_elements += 1;
        }
        else if( total == this->heapSize ) {
            int freq = this->minFreq();
            add.frequency = freq+1;
            int i_hash = newHashItem(s,0);
            add.index_hash = i_hash;
            this->Heap[0] = add;
        }
    }
    this->heapSort();
    this->counter += 1;
}

string HeapHash::printHeap() {
    int t = this->total_elements;
    for(int j = 0; j < t-1; j++) {
        checkNodes(j,j+1);
    }
    stringstream ss;
    for(int i = 0; i < t; i++) {
        ss << (this->Heap[i]).item << ":" << (this->Heap[i]).frequency << ",";
    }
    return ss.str();
}
