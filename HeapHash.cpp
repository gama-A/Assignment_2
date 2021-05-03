// Gama Aristondo, 8404071
//
// Function definitions for "HeapHash.h"

#include <cmath>
#include <iostream>
#include <functional>
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
    string item = (this->heap[0]).item;
    int hashIndex = this->findElement(item);
    struct heapItem nullHeap_Item;
    nullHeap_Item.frequency = 0;
    nullHeap_Item.age = 0;
    nullHeap_Item.item = "";
    struct hashItem nullHash_Item;
    nullHash_Item.s = "";
    nullHash_Item.index_heap = 0;
    this->heap[0] = nullHeap_Item;
    this->hash[hashIndex] = nullHash_Item;
    return freq;
}

void HeapHash::newHashItem(string s, int index) {
    struct hashItem add;
    add.s = s;
    add.index_heap = index;
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

void HeapHash::reorganizeStructure() {
    int t = this->total_elements;
    for(int i = t/2 - 1; i >= 0; i--) {
        this->percolateDown(i);
    }
    for(int j = t; j > 0; j--) {
        this->updateHash(j);
    }
}

void HeapHash::percolateDown(int i) {
    int child = (2*i) + 1;
    struct heapItem temp = this->heap[i];
    while(child <= this->total_elements) {
        if( (this->heap[child]).frequency > (this->heap[child+1]).frequency ) {
            child += 1;
        }
        else if( (this->heap[child]).frequency == (this->heap[child+1]).frequency ) {
            int c = breakTie(child, child+1);
            if( c == child+1 ) {
                child += 1;
            }
        }
        else if( (temp.frequency) < (this->heap[child]).frequency ) {
            break;
        }
        else if( (temp.frequency) == (this->heap[child]).frequency ) {
            int b = breakTie(i,child);
            if(b == i) {
                break;
            }
        }
        this->heap[i] = this->heap[child];
        i = child;
        child = 2*child;
    }
}

int HeapHash::breakTie(int index_1, int index_2) {
    struct heapItem temp1 = this->heap[index_1];
    struct heapItem temp2 = this->heap[index_2];
    if(temp1.age > temp2.age) {
        return index_1;
    }
    return index_2;
}

void HeapHash::updateHash(int index) {
    struct heapItem temp;
    temp = this->heap[index];
    string search = temp.item;
    int h_index = this->findElement(search);
    (this->hash[h_index]).index_heap = index;
}

HeapHash::HeapHash(int K) {
    int prime;
    prime = smallestPrime(K);
    struct heapItem initial_Heap;
    initial_Heap.frequency = 0;
    initial_Heap.age = 0;
    initial_Heap.item = "";
    struct hashItem initial_Hash;
    initial_Hash.s = "";
    initial_Hash.index_heap = 0;
    this->hash.resize(prime,initial_Hash);
    this->heap.resize(K,initial_Heap);
    this->heapSize = K;
    this->hashSize = prime;
    this->total_elements = 0;
    this->counter = 0;
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
        struct heapItem add;
        add.age = age;
        add.item = s;
        if( total < this->heapSize ) {
            add.frequency = 1;
            this->heap[total] = add;
            this->total_elements += 1;
            this->newHashItem(s,total+1);
        }
        else if( total_elements == this->heapSize ) {
            int freq = this->deleteMin();
            add.frequency = freq+1;
            this->heap[0] = add;
            this->newHashItem(s,0);
        }
    }
    this->reorganizeStructure();
    this->counter += 1;
}

string HeapHash::printItems() {
    int K = this->heapSize;
    stringstream ss;
    for(int i = 0; i < K; i++) {
        ss << (this->heap[i]).item << ":" << (this->heap[i]).frequency << ",";
    }
    return ss.str();
}
