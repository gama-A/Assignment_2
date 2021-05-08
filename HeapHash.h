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
    
    std::string printHeap();
    // prints out min heap to write to output file

    struct heapItem {
        int frequency;
        int age;
        std::string item;
        int index_hash;
    };
    
    struct hashItem {
        std::string item;
        int index_heap;
    };

    private:
    std::vector<struct heapItem> Heap;
    // contains the frequency of the string

    std::vector<struct hashItem> Hash;
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

    int minFreq();
    // returns the frequency of the minimum heap item (at root)

    int newHashItem(std::string s, int index);
    // inputs new element into the hash table
    // arguments are the string and newly place heap index

    void heapSort();
    // ran after each insert to heapify the heap and update
    // hash indexes

    void heapify(int i);
    // helper function for reorganizeStructure()

    int breakTie(int index_1, int index_2);
    void swapNodes(int index_l, int index_r);
    void checkNodes(int index_1, int index_2);
    void updateHash(int index);
    void checkHash(int index);

};

#endif
