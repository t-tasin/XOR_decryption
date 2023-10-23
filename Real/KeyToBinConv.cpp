#include <iostream>
#include <string>
#include <bitset>
#include <fstream>
#include <algorithm>
using namespace std;

class K2BConverter{
    public:
    string keysList[17576];
    string binKeysList[17576];

    K2BConverter::K2BConverter(int i){
        combinations();
        //cout<<"Finished Creation\n";
        convert();
        //cout << "Finished Conversion";
        //MEGA();
    }
    
    int combinations(){
        string arr [] = {"a","b","c","d","e","f","g",
                        "h","i","j","k","l","m","n",
                        "o","p","q","r","s","t","u",
                        "v","w","x","y","z"};

        //I forgot how to dynamically increase the size of an array in c++ so I used the count variable to find out
        // how many combinations there were and then used that to declare and initialize the keyCombinations array.
        int count = 0;
        //for loop for the first letter in combinations
        for (int i = 0; i <= 25; i++){
            //for loop for the second letter in combinations
            for (int j = 0; j <= 25; j++){
                //for loop for the third letter in combinations
                //This is where the combinations are appended to the keyCombinations array
                for (int h = 0; h <= 25; h++){
                    this->keysList[count] = arr[i] + arr[j] + arr[h];
                    count ++;
                }
            }
        }
        return 0;
    }

    int convert(){
        for (int i=0; i<17576; i++){
            string key = this->keysList[i];
            string binKey;
                for(auto &c : key){
                    binKey += bitset<8>(c).to_string();
                }
            this->binKeysList[i]=binKey;
        }
        return 0;
    }
    int MEGA(){
        for (int x=0;x<17576;x++){
            cout << keysList[x] << " " << binKeysList[x] << "\n";
        }
        return 0;
    }
};

int main(){
    K2BConverter c(3);
    return 0;
}