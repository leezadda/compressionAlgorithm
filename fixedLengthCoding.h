// Add the include guard
#ifndef FIXEDLENGTHCODING_H
#define FIXEDLENGTHCODING_H

#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

struct symbol
{
    char character;
    int frequency;
    string code;
};


class fixedLengthCoding{
    private:
        string message;
        int alphabetSize;
        struct symbol *alphabet = nullptr;

    public:
    fixedLengthCoding(); //default
    ~fixedLengthCoding(); //deconstructor
    string getMessage(); //message getter
    int getAlphabetSize(); //alphabet size getter
    
    int readFromFile(const string &);   //same as PA2 
    void createAlphabet();  //same as PA2 
    void printAlphabet();   //same as PA2 
    void printHistogram();  //same as PA2 
    void printCodes();  //same as PA2 
    
    string BinaryString(int number); //creates binary codes (extra function)

};






#endif
