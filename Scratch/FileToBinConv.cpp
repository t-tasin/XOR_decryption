#include <iostream>
#include <string>
#include <bitset>
#include <fstream>
using namespace std;

class F2BConverter {
  public:
    string filepath;

  string convertFull(string fileName){
    filepath = fileName;
    string fileString = fileToString(fileName);
    string bitString = strToBin(fileString);
    return bitString;
  }
  string strToBin(string toConvert){
    string bitString;
    for (int i = 0; i < toConvert.length(); i++) { 
        string tString = bitset<8>(toConvert[i]).to_string();
        bitString += tString;
        }
    return bitString;
  }
  string fileToString(string fileName){
    string fileString;
    ifstream file;
    cout << fileName;
    file.open(fileName);
    while(file){
      cout << file;
      /*fileString += file.get();
      cout << fileString;*/
      }
    file.close();
    return fileString;
  }
};

int main(){
  F2BConverter conv;
  string c = conv.convertFull("testFile.txt");
  cout << c;
  return 0;
}