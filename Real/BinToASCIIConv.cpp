#include <iostream>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

class B2AConverter {
    public:
    // no constructor, create an instance, then call setup() with the bitstring

    string setup(string bitstring){
        string two; // ill make real names later (she will not do that)
        string hold;
        //cout << "Bitstring Length: " << bitstring.length() << "\n";
        for (int i=0; i<bitstring.length(); i++){
            if (bitstring[i]!=','){
                hold += bitstring[i];
                //cout << "standard: " << bitstring[i] << "\n";
            } else {
                two += convert(hold);
                //cout << "Converting: " << hold <<"\n";
                hold = "";
                //cout << "total output so far: " << two << "\n";
            }
        }
        two += convert(hold); // for the last set of bits bc there is no comma to trigger the conversion
        return two;
    }

    string convert(string hold){
        stringstream sstream(hold);
        string output;
        while(sstream.good()){
            bitset<8> bits;
            sstream >> bits;
            char c = char(bits.to_ulong());
            output += c;
        }
    return output;
    }
};

/*
int main(){
    B2AConverter c;
    string a = c.setup("01101001,01100101,01101101,01101100,01101110"); // This is the binary for 105,101,109,108,110 generated by FileToBinConv, it should return i,e,m,l,n
    cout << a << "\n";
}
*/