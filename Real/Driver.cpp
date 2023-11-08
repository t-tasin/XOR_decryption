#include <iostream>
#include <sstream>
#include <bitset>
#include <string>

#include ".\BinToASCIIConv.cpp"
#include ".\decryptionTool.cpp"
#include ".\FileToBinConv.cpp"
#include ".\KeyToBinConv.cpp"

#include ".\Decrypter.cpp"

using namespace std;

class Driver{
    private:
    string binString;

    public:
    string Filepath;  
    F2BConverter F2BConv;
    K2BConverter K2BConv; //call the get(id) method to get a given key
    B2AConverter B2AConv;
    Decrypter Decrypt;
    
    string why[2000];

    void setFile(string Filepath){
        this->Filepath = Filepath;
        this->F2BConv.setup(Filepath);
        this->binString = F2BConv.convertFull();
    }

    string keyConvert(int keyID){
        if (keyID < 0 || keyID > 17575){
            cout << "keyIndex out of range\nKey IDs range from 0 to 17575\n";
            return "void";
        }
        string xored;
        string asciid;
        string decrypted;
        string key = K2BConv.get(keyID);
        cout << "Key: " << K2BConv.get(keyID,false) << "\n";
        xored = Decrypt.decrypt(this->binString,key);
        asciid = binToInt(xored);
        cout << "Ascii Codes: " << asciid << "\n";
        decrypted = B2AConv.setup(xored);
        cout << "Decrypted: " << decrypted << "\n";
        return asciid;
    }

    string binToInt(string xor){
        string set;
        string nums;
        for (int i = 0; i < xor.length(); i++) { 
            if (xor[i]==','){
                nums += to_string(stoi(set, nullptr, 2)) + ",";
                set = "";
            } else {set += xor[i];}
        }
        nums += to_string(stoi(set, nullptr, 2));
        set = "";
        return nums;
    }
};

int main(){
    Driver d;
    d.setFile("testFile.txt");
    for(int i=0;i<17576;i++){d.keyConvert(i);}
}
