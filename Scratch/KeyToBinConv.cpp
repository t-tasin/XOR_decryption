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

    K2BConverter::K2BConverter(){
        // Roadblock: Do not have the getkeys function
        //this->keysList = getKeys();
        Convert();
    }

    int Convert(){
        for (int i=0; i<17576; i++){
            string key = this->keysList[i];
            string binKey;
                for(auto &c : key){
                    binKey += bitset<8>(c).to_string();
                }
            this->binKeysList[i]=binKey;
        }
    }
}