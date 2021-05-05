// Gama Aristondo, 8404071
//
// main.cpp

#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>

#include "HeapHash.h"

using namespace std;

int main(int argc, char** argv) {
    string in(argv[1]);
    string out(argv[2]);
    int K = atoi(argv[3]);
    ifstream infile;
    infile.open(in);
    string s;
    HeapHash array(K);
    while(getline(infile,s,',')) {
        array.insert(s);
    }
    infile.close();
    ofstream outfile(out);
    outfile << array.printHeap();
    outfile.close();
    return 0;
}
