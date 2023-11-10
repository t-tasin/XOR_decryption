#include <iostream>
#include <sstream>
#include <bitset>
#include <string>

#include ".\BinToASCIIConv.cpp" //
#include ".\FileToBinConv.cpp" //
#include ".\KeyToBinConv.cpp" //

#include ".\Decrypter.cpp" //
#include ".\commonWordCompare.cpp" //

using namespace std;

class Driver{
    private:
    string binString;
    bool setup = false;
    
    public:
    string Filepath;  
    F2BConverter F2BConv;
    K2BConverter K2BConv; //call the get(id) method to get a given key
    B2AConverter B2AConv;
    Decrypter Decrypt;
    Comparer Comp;

    int highKeyID = 0;
    int highKeyPercent = 0;

    string run(bool loud = false){ // set loud to true for fun printouts as it works (takes longer)
        cout << "running\n";
        if (!this->setup){
            cout << "Please set file before running\n";
        } else {
            for (int i = 0;i<17576;i++){
                int per = keyConvert(i, loud);
                if (per > this->highKeyPercent){
                    this->highKeyID = i;
                    this->highKeyPercent = per;
                    cout << "New Best Key Found: " << K2BConv.get(i,false) << endl;
                }
            }
            if (this->highKeyPercent==0){
                cout << "No subitble key was found\n";
            } else {
                cout << "Key found: " << K2BConv.get(this->highKeyID,false)<< "\n";
            }
        }
    return K2BConv.get(this->highKeyID,false);
    }
    
    void setFile(string Filepath){
        this->Filepath = Filepath;
        this->F2BConv.setup(Filepath);
        this->binString = F2BConv.convertFull();
        this->setup = true;
    }

    int keyConvert(int keyID, bool loud = false){
        if (keyID < 0 || keyID > 17575){
            cout << "keyIndex out of range\nKey IDs range from 0 to 17575\n";
            return -1;
        }
        string xored;
        string asciid;
        string decrypted;
        string key = K2BConv.get(keyID);
        //cout << "Key: " << K2BConv.get(keyID,false) << "\n";
        xored = Decrypt.decrypt(this->binString,key);
        decrypted = B2AConv.setup(xored);
        //cout << "Decrypted: " << decrypted << "\n";
        int correctPer = Comp.wordCompare(decrypted,loud);
        return correctPer;
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
    d.run(true);
}
