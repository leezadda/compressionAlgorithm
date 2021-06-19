#include <iostream>
#include <cmath>


using namespace std;

int main() {
    
    //inputs for entry message array
    const int SIZE = 100;
    char myArr[SIZE];
    
    //Turns all elements in myArr into 'NULL'
    for (int i = 0; i < SIZE; i++){
        myArr[i] = NULL;}
     
    //ask user for their array
    cin.getline(myArr, 100);
    
    //creates a array with 100 'true' elements
    bool uniqueSymbolArr[SIZE];
    int symbolCount[SIZE];
     
    for (int i = 0; i < SIZE; i++){
        uniqueSymbolArr[i] = true;
        symbolCount[i] = 1;
    }
    
    //DON't Touch (it turns true array into false if it has duplicates)
    for (int i = 0; i < SIZE; i++){
            for (int j = i + 1; j < SIZE; j++){
                    if(myArr[i] == myArr[j]){
                        uniqueSymbolArr[j] = false;
                        symbolCount[i] = symbolCount[i] + 1;
                    }
                    if(myArr[i] == 0){
                        uniqueSymbolArr[i] = false;
                        symbolCount[i] = 0;
                        }
                }
        }

    //assigns unique symbols valiues to alphabet
    char alphabetArr[SIZE];
    for (int i = 0; i < SIZE; i++){
        if(uniqueSymbolArr[i] == true)
            alphabetArr[i] = myArr[i];
        else{
            alphabetArr[i] = NULL;
        }
    }
    
    //F I N A L  O U T P U T
    
    //"Message: "
cout << "Message: " << myArr << endl;
    
    //"Number of symbols in the alphabet = "
    int symbolCounter = 0;
    for (int i = 0; i < SIZE; i++){
        symbolCounter = symbolCounter + uniqueSymbolArr[i];}
    cout << "Number of symbols in the alphabet = " << symbolCounter << endl;
      
    //"Characters in the alphabet = "
    cout << "Characters in the alphabet = ";
            for (int i = 0; i < SIZE; i++){
            if(alphabetArr[i] != 0){
                if(i > 0)
                cout << ',';
                cout << alphabetArr[i];
     }
    }
        
    cout << endl;
    
    //Number of bits per symbol = #
    int bitsPerSymbol = 0;
    bitsPerSymbol = ceil(log2(symbolCounter));
cout << "Number of bits per symbol = " << bitsPerSymbol << endl;
    
    //Histogram showing the frequency of the symbols in the alphabet
    cout << "Histogram showing the frequency of the symbols in the alphabet" << endl;
    
        for (int i = 0; i < SIZE; i++){
            if(alphabetArr[i] != 0){
                cout << alphabetArr[i] << " | ";
                for(int x = 0; x < symbolCount[i]; x++){
                cout << '*';}
                cout << endl;}
        }
    
        return 0;
    }
    
