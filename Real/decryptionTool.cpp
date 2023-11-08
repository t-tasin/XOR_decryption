//Amelia
//10/20/23

#include <iostream>

using namespace std;



void decryptionTool (string message, string key){
    //get length of binary message and key, and creates variables to hold those value
    int messageLen = message.length();
    int keyLen = key.length();
    string decryptedMessage = "";

    //for loop to interate through the binary message
    //Variable to track what index in the key the for loop is currently at
    int j = 0;
    //Goes through comparing and decrypting the message with the given key (parameter)
    for (int i = 0; i < messageLen; i++){
        if (j >= keyLen){
            j = 0;
        }
        //if the value of the message matches the value of the key a 0 will be added to the decrypted message
        if (message[i] == key[j]){
            decryptedMessage = decryptedMessage + "0";
        //if the value of the message does not matches the value of the key a 0 will be added to the decrypted message
        } else {
            decryptedMessage = decryptedMessage + "1";
        }
        //Adds one to the key index tracker
        j++;
    }

    //prints the decrypted message. The message is still in binary.
    cout << decryptedMessage << endl;
}
