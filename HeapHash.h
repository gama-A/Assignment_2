// Gama Aristondo, 8404071
//
// Header file for data structures

#ifndef HEAPHASH_H
#define HEAPHASH_H

#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <string>

class HeapHash
{
    public:
    HeapHash(int K);
    // Initialize structure to hold top-K elements

    ~HeapHash();
    // Destructor

    void insert(std::string s);
    // checks condition of heap/hash and inserts/increments

    private:
    int *heap;
    // contains the frequency of the string

    std::vector<std::pair<std::string,*int>> hash;
    // contains string and pointer to heap

    const size_t sizeHeap;
    const size_t sizeHash;

    int smallestPrime(int K);
    bool isPrime(int n);

};

#endif
