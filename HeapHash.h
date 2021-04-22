// Gama Aristondo, 8404071
//
// Header file for data structures

#ifndef HEAPHASH_H
#define HEAPHASH_H

#include <iostream>
#include <vector>
#include <utility>
#include <hash>

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
    std::vector<std::pair<int,*int>> hash;

    void smallestPrime(int K);

};

#endif
