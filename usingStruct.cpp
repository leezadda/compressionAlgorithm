#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "functions.h"

using namespace std;

int main()
{

    string message,filename;
    const long int len = message.length();
    symbol * alphabet = new symbol[len];


    cin >> filename;
    if(readFromFile(filename, message)==0)
    {
        cout << "Message: " << message << endl;
        createAlphabet(message, alphabet);
        cout << "Number of symbols in the alphabet = " << myLength(message, alphabet) << endl;
        cout << "Characters in the alphabet = ";
        printAlphabet(message, alphabet);
        cout << "Number of bits per symbol = " << ceil(log2(myLength(message, alphabet))) << endl;
        printHistogram(message, alphabet);
        printCodes(message, alphabet);
    }
    else
        cout << "File not found." << endl;
        
        delete[] alphabet;
        alphabet = NULL;
        
        
    return 0;

    
}



