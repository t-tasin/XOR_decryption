#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
using namespace std;

class B2AConverter {
    public:
    string bits;

    B2AConverter::B2AConverter(string bitstring){
        this->bits = bitstring;
        convert();
    }


    int convert(){
        stringstream sstream(this->bits);
        string output;
        while(sstream.good()){
            bitset<8> bits;
            sstream >> bits;
            char c = char(bits.to_ulong());
            output += c;
        }
    cout << output;
   return 0;
    }
};