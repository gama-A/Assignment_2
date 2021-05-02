// Gama Aristondo, 8404071
//
// main.cpp

#include <iostream>
#include <hash>
#include <string>
#include <vector>
#include <utility>
#include <fstream>

#include "HeapHash.h"

using namespace std;

int main(int argc, char** argv) {
    string in(argv[1]);
    string out(argv[2]);
    int K(argv[3]);
    ifstream infile;
    infile.open(in);
    string s;
    HeapHash array;
    while(getline(infile,s,',')) {
        array.insert(s);
    }
    ofstream outfile(out);
    outfile << array.printItems();
    outfile.close();
    return 0;
}
