#include "fixedLengthCoding.h"

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//DEFAULT CONSTRUCTOR
    fixedLengthCoding::fixedLengthCoding()
    {
        message = "";
        alphabetSize = 0;
        struct symbol *alphabet = nullptr;
    }
    
//DESTRUCTOR
    fixedLengthCoding::~fixedLengthCoding()
    {
        if(alphabet != nullptr)
        {
            delete [] alphabet;
        }
    }
    
//MESSAGE GETTER
    string fixedLengthCoding::getMessage(){
        return message;
    }
    
//ALPHABET SIZE GETTER
int fixedLengthCoding::getAlphabetSize()
{
    return alphabetSize;
}

//READ FROM FILE
    int fixedLengthCoding::readFromFile(const string & filename)
{ 
        ifstream theFile(filename);
        if(!theFile.is_open()){
            return -1;
    }
    else
    {
    theFile >> alphabetSize;
    while (!theFile.eof())
    {
        getline(theFile, message);
    }    
    theFile.close();

    return 0;
    }
}

//CREATE ALPHABET
void fixedLengthCoding::createAlphabet()
{
    //creates alphabet's array
        alphabet = new struct symbol[message.length()];
    
//LOOP GOES THROUGH MESSAGE AND GIVES EACH CHARACTER A: CHAR, FREQUENCY, AND CODE.
    for(int i = 0; i < message.length(); i++)
    {
        alphabet[i].character = message[i];
        alphabet[i].frequency = 1;
        alphabet[i].code = "";
    }
       
//LOOP GOES THROUGH MESSAGE AND REMOVES REPEATING CHARACTERS.
    for (int i = 0; i < message.length(); i++)
    {
        for (int j = i + 1; j < message.length(); j++)
        {
            if(alphabet[i].character == alphabet[j].character)
            {
                alphabet[i].frequency++;
                alphabet[j].character = 0;
            }
        }
    }
        
//GIVE UNIQUE CHARS A CODE (0 TO N)
    int began = 0;
        for(int u = 0; u < message.length(); u++)
        {
            if(alphabet[u].character != 0)
            {
                alphabet[u].code = BinaryString(began);
                began++;
            }
        }
}

//PRINT THE ALPHABET
    void fixedLengthCoding::printAlphabet()
    {
        for(int i = 0; i < message.length(); i++)
        {
            if(alphabet[i].character != 0)
            {
                if(i > 0)
                    cout << ',';
                    cout << alphabet[i].character;

            }
        }
        
        cout << endl;
    }

//PRINT HISTOGRAM   
    void fixedLengthCoding::printHistogram(){
        cout << "Histogram showing the frequency of the symbols in the alphabet" << endl;
        for(int i = 0; i < message.length(); i++)
        {
            if(alphabet[i].character != 0)
            {
                cout << alphabet[i].character << " | ";
                for(int x = 0; x < alphabet[i].frequency; x++)
                {
                    cout << '*';
                }
            cout << endl;
        }
        
    }

}

//PRINT CODES
    void fixedLengthCoding::printCodes()
    {
        cout <<"Fixed-length codes of the symbols in the alphabet" <<endl;
        int begin = 0;
        for(int i = 0; i < message.length(); i++)
        {
            if(alphabet[i].character != 0)
            {
            cout << alphabet[i].character << " | ";
            cout << setw(ceil(log2(alphabetSize))) << setfill('0') << alphabet[i].code << endl;
            begin++;
            }             
        }
    }  
    
//CREATES BINARY CODES   
    string fixedLengthCoding::BinaryString(int number)
    {
        if(number == 0)
        {
            return "0";
        }
        else if(number == 1)
        {
            return "1";
        }
        else
        {
            return BinaryString(number/2) + BinaryString(number%2);
        }
    }    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    