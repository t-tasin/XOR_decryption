//Amelia & Nathan
//11/08/23
#include <iostream>
#include <string>
#include <fstream>


using namespace std;


//Will compare the decrypted message to a file of common words and
//return an int value of the percentage.

int wordCompare (string decryptedMessage){

    int messageLength = decryptedMessage.length();
    int spaceNum = 0;
    for (int i = 0; i < messageLength; i++){
        if (decryptedMessage[i] == ' '){
            spaceNum++;
        }
    }
    //string messageArray[spaceNum+1];
    string * messageArray = new string[spaceNum+1];
    string newWord = "";
    int count = 0;
    for (int i = 0; i <= messageLength; i++){
        if ((decryptedMessage[i] != ' ' ) && (decryptedMessage[i] != '\0') ){
            newWord = newWord + decryptedMessage[i];
        } else {
            messageArray[count] = newWord;
            cout << newWord << endl;
            count++;
            newWord = "";

        }
    }



    //counts total number of words in decrypted message
    //int numOfWords = 0; // Use count Variable
    //counts total number of words that are in the decrypted message that match a word in the common words file
    int commonWordsFound = 0;

    ifstream file;
    string fileContents;

    file.open("./commonWords.txt");
    file >> fileContents;

    if (file.is_open()){
        string commonWordArray[5000];
        for (int j = 0; j < count; j++) {
            for (int i = 0; i < 5000; i++)
            {
                getline(file, commonWordArray[i], '\n');
                if (commonWordArray[i] == messageArray[j]) {
                    commonWordsFound++;
                }
            }
        }

//        for (int i = 0; i < count; i++){
//            for ( int j = 0; j < 5000; j++)
//                if ( commonWordArray [i] != messageArray[j]){
//                    commonWordsFound++;
//                }
//        }

    } else {
        cout << "The file didn't open correctly" << endl;
    }

    //calculates the percent value of the amount of common words in the decrypted message
    int percentOfCommonWords = (commonWordsFound*100)/count;
    return percentOfCommonWords;
}

int main(){
    int c = wordCompare("104,101,108,108,111");
    cout << c << "\n";
}
