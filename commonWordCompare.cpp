//Amelia & Nathan
//11/08/23
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//Will compare the decrypted message to a file of common words and
//return an int value of the percentage.
class Comparer {
    public:
    vector<string> commonWords;

    Comparer(){
        generateWordsArray();
    }

    int wordCompare (string decryptedMessage, bool loud = false){
        if (loud){
            cout << "Message: " << decryptedMessage << endl;
        }
        int foundWords = 0;
        int messageLength = decryptedMessage.length();
        string newWord = "";
        int count = 0;
        for (int i = 0; i <= messageLength; i++){
            if (decryptedMessage[i] != ' '){
                newWord = newWord + decryptedMessage[i];
            } else {
                count++;
                for (int x = 0; x<this->commonWords.size(); x++){
                    if (newWord == this->commonWords[x]){
                        foundWords += 1;
                        break;
                    }
                }
                newWord = "";
            }
        }
        newWord = newWord.substr(0, newWord.length()-1); // removes the hidden ending char that c++ sticks on because it hates me personally =)
        count++; // call the check for the last characters as they dont have a space at the end
        for (int x = 0; x<this->commonWords.size(); x++){
            if (newWord == this->commonWords[x]){
                foundWords += 1;
                break;
            }
        }
        //counts total number of words in decrypted message
        //int numOfWords = 0; // Use count Variable
        //counts total number of words that are in the decrypted message that match a word in the common words file
        //calculates the percent value of the amount of common words in the decrypted message
        return (foundWords * 100)/count;
    }
    void generateWordsArray(){
        ifstream file;
        string fileContents;

        file.open("./commonWords.txt");
        if (file.is_open()){
            for (int x=0;x<5000;x++){
                file >> fileContents;
                this->commonWords.insert(commonWords.begin(),fileContents);
            }
            file.close();
        } else {
            cout << "The file didn't open correctly" << endl;
        }
    }
};