//Amelia & Nathan
//10/27/23

#include <iostream>
#include <string>

using namespace std;

string numbersToWords (string asciiMessage){
    int len = asciiMessage.length();

    string letterMessage = "";

    cout << asciiMessage << endl;
    string tempASCII = "";
    int tempNum = 0;
    for (int i = 0; i <= len; i++){
        if ((asciiMessage[i] != ',')) {
            tempASCII = tempASCII + asciiMessage[i];
        } else {
            tempNum = stoi(tempASCII);
            letterMessage = letterMessage + char(tempNum);
            tempASCII = "";
        }
    }
    tempNum = stoi(tempASCII);
    letterMessage = letterMessage + char(tempNum);

    cout << letterMessage << endl;
    return letterMessage;
}
