#include <iostream>
#include <string>
#include <sstream>
#include <bitset>

#include ".\BinToASCIIConv.cpp"
#include ".\decryptionTool.cpp"
#include ".\FileToBinConv.cpp"
#include ".\KeyToBinConv.cpp"

#include ".\Decrypter.cpp"

using namespace std;

class Driver{
    public:
    string Filepath;  
    F2BConverter F2BConv;
    K2BConverter K2BConv; //call the get(id) method to get a given key
    B2AConverter B2AConv;
    Decrypter Decrypt;
    string decryptedStrings[17576];


    Driver::Driver(string filePath){
        this->Filepath = filePath;
        F2BConv.setup(filePath);
    }

    int keyConvert(){
        string binString = F2BConv.convertFull();
        string xored;
        string asciid;
        string decrypted;
        for (int i=0;i<17576;i++){
            xored = Decrypt.decrypt(binString,K2BConv.get(i));
            //cout << xored << "\n";
            asciid = binToInt(xored);
            //cout << asciid << "\n";
            //decrypted = B2AConv.setup(xored);
            //cout << decrypted << "\n";
            this->decryptedStrings[i] = asciid;
        }
        return 0;
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

    string getDecoded(int id){
        return this->decryptedStrings[id];
    }
};

int main(){
    cout << "here1\n";
    Driver d("testFile.txt");
    d.keyConvert();
    cout << "here\n";
    d.getDecoded(17574);
}
