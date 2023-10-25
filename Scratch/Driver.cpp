#include <iostream>
#include <string>
#include <sstream>
#include <bitset>

#include "..\Real\BinToASCIIConv.cpp"
#include "..\Real\decryptionTool.cpp"
#include "..\Real\FileToBinConv.cpp"
#include "..\Real\KeyGenerator.cpp"
#include "..\Real\KeyToBinConv.cpp"

using namespace std;

class Driver{
    public:
    string Filepath;  
    F2BConverter F2BConv;  
    K2BConverter K2BConv;
    B2AConverter B2AConv;

    Driver::Driver(string filePath){
        this->Filepath = filePath;
    }
};
