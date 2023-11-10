#include <iostream>
using namespace std;


class Decrypter{
    public:

    string decrypt (string message, string key){
        //get lengths of binary message and key and creates a variable to hold the value
        int messageLen = message.length();
        int keyLen = key.length();
        string decryptedMessage = "";

        //for loop to interate through the binary message
        //Variable to track what index in the key the for loop is currently at
        int j = 0;
        //Goes through comparing and decrypting the message with the given key (parameter)
        for (int i = 0; i < messageLen; i++){
            //cout << decryptedMessage << endl;
            if (j >= keyLen){
                j = 0;
            }

            if (message[i] == key[j]){
                decryptedMessage = decryptedMessage + "0";
                j++;
            } else if (message[i] == ',') {
                    decryptedMessage = decryptedMessage + ",";


            } else {
                decryptedMessage = decryptedMessage + "1";\
                j++;
            }
        }
        return decryptedMessage;
    }
};