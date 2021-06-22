#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

struct symbol
{
    char character;
    int frequency;
    string code;
};


string BinaryString(int number){ //functions turns number into binary using recursion
    if(number == 0){
        return "0";
    }
    else if(number == 1){
        return "1";
    }
    else{
        return BinaryString(number/2) + BinaryString(number%2);
    }
}



int myLength(string message, symbol alphabet[]){
    
    //SIZE OF UNIQUE SYMBOL ARRAY
    int lenCounter = 0;
    for(int i = 0; i < message.length(); i++){
        if(alphabet[i].character != 0){
            lenCounter++;}
        }
return lenCounter;
}


//-------------------------------------------------------

int readFromFile(string file, string & message) { // D O N E
ifstream theFile(file);
if(!theFile.is_open()){
    return -1;
}else{
while (getline(theFile, message)) {
  theFile >> message;
}
theFile.close();
}
return 0;
}




void createAlphabet(string message, symbol alphabet[]){

    
    //LOOP GOES THROUGH MESSAGE AND GIVES EACH CHARACTER A: CHAR, FREQUENCY, AND CODE.
    for(int i = 0; i < message.length(); i++){
            alphabet[i].character = message[i];

            alphabet[i].frequency = 1;

            alphabet[i].code = "";
    }
    //LOOP GOES THROUGH MESSAGE AND REMOVES REPEATING CHARACTERS.
    for (int i = 0; i < message.length(); i++){
            for (int j = i + 1; j < message.length(); j++){
                    if(alphabet[i].character == alphabet[j].character){
                        alphabet[i].frequency++;
                        alphabet[j].character = 0;
                    }
                }
        }
        //loop adds string codesto unique characters

    int begin = 0;
    for(int i = 0; i < message.length(); i++){
        if(alphabet[i].character != 0){
        alphabet[i].code = BinaryString(begin);
            begin++;
        }
    }
}
 
void printAlphabet(string message, symbol alphabet[]){
    
    long int len = message.length();
    for(int i = 0; i < len; i++){
        if(alphabet[i].character != 0){
            if(i > 0)
            cout << ',';
            cout << alphabet[i].character;

            }
        }
     
    cout << endl;
}


void printHistogram(string message, symbol alphabet[]){
long int len = message.length();
    cout << "Histogram showing the frequency of the symbols in the alphabet" << endl;
    for(int i = 0; i < len; i++){
        if(alphabet[i].character != 0){
            cout << alphabet[i].character << " | ";
            for(int x = 0; x < alphabet[i].frequency; x++){
                cout << '*';}
            cout << endl;
        }
        
    }

}

void printCodes(string message, symbol alphabet[]){
    long int len = message.length();
    
cout <<"Fixed-lenght codes of the symbols in the alphabet" <<endl;
int begin = 0;
    for(int i = 0; i < len; i++){
        if(alphabet[i].character != 0){
            cout << alphabet[i].character << " | ";
            //cout << setw(ceil(log2(myLength(message, alphabet)))) << setfill('0') << alphabet[i].code << endl;
            cout << setw(ceil(log2(myLength(message, alphabet)))) << setfill('0') << BinaryString(begin) << endl;
            begin++;
            
        }             
        } 
    }




#endif


