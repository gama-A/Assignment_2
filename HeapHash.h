// Gama Aristondo, 8404071
//
// Header file for data structures

#ifndef HEAPHASH_H
#define HEAPHASH_H

#include <iostream>
#include <functional>
#include <vector>
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

    struct heapItem {
        int frequency;
        int age;
        std::string item;
    };
    
    struct hashItem {
        std::string s;
        int index_heap;
    };

    std::vector<struct heapItem> heap;
    // contains the frequency of the string

    std::vector<struct hashItem> hash;
    // contains string and index in heap array

    int total_elements;
    int heapSize;
    int hashSize;
    int counter;

    int smallestPrime(int K);
    bool isPrime(int n);
    // two helper functions to find size of the hash table

    int findElement(std::string s);
    // helper function to find if element already exists
    // if it does return index, if it does not return -1
};

#endif
