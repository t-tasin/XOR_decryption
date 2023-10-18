#include <iostream>
#include <string>
#include <bitset>
#include <fstream>
#include <algorithm>
using namespace std;

class F2BConverter {
  public:
    string filepath;
    bool isTXT;
    bool is09;
    char charList[11] = {'1','2','3','4','5','6','7','8','9','0',','};

    F2BConverter::F2BConverter(string file_path){
      checkForTXT(file_path);
      this->is09 = false;
      this->filepath = file_path;
    }

  int checkForTXT(string filepath){
    int len = filepath.length();
    string txtCheck = filepath.substr(len-4);
    transform(txtCheck.begin(), txtCheck.end(), txtCheck.begin(), ::toupper); 
    if (txtCheck == ".TXT"){
      this->isTXT = true;
    } else {
      this->isTXT=false;
      }
    return 0;
  }

  string convertFull(){
    if (this->isTXT){
      string fileString = fileToString();
      string bitString = strToBin(fileString);
      return bitString;
    }
    cout << "Given file was not a .txt file";
    return "null";
  }

  string strToBin(string toConvert){
    string bitString;
    for (int i = 0; i < toConvert.length(); i++) { 
      if (toConvert[i]==','){ // keeps the commas not converted to binary
        bitString += toConvert[i];
      } else {
        string tString = bitset<8>(toConvert[i]).to_string();
        if (tString == "11111111"){ // the ' ' is excluded here
        //As im not positive all txt files will have them, its easier to ignore when it shows up instead of looking for and removing it
          ;
        }
        else {
          bitString += tString;
        }
      }
    }
    return bitString;
  }

  string fileToString(){
    string fileString;
    fstream file;
    file.open("testFile.txt");
    while(file){
      char c = file.get();
      bool charCheck = false;
      for (int i=0; i<11; i++){
        if (c==this->charList[i] || bitset<8>(c).to_string()=="11111111"){ // get reads in ' 'with bit pattern 11111111
          //this is ignored elsewhere so it just passes here
          charCheck = true;
          break;
        }
      }
      if (charCheck==false){
        this->is09 = false;
        break;
      }else{
        fileString += c;
      }
    }
    this->is09 = true;
    file.close();
    return fileString;
  }
  bool beget(){
    return this->is09;
  }
};

int main(){
  F2BConverter conv("testFile.txt");
  string c = conv.convertFull();
  cout << c << "\n";
  cout << conv.beget();
  return 0;
}