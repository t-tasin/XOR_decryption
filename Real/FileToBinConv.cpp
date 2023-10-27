#include <iostream>
#include <string>
#include <bitset>
#include <fstream>
#include <algorithm>
using namespace std;

class F2BConverter {
  public:
    string filepath;
    bool isTXT = true;
    bool is09 = true;
    bool lessThan50 = true;
    bool withinLimit = true;
    char charList[12] = {'1','2','3','4','5','6','7','8','9','0',',','-'};

    // no constructor for this class. Instead initialize an instance, use setup(), and then convertFull()

  int setup(string file_path){
    checkForTXT(file_path);
    this->filepath = file_path;
    return 0;
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
    string sumChars;
    for (int i = 0; i < toConvert.length(); i++) { 
      if (toConvert[i]==','){ // keeps the commas not converted to binary
        if ((stoi(sumChars)>255) || (stoi(sumChars)<0)){
          this->withinLimit = false;
          cout << "number out of range: " << sumChars << "\n";
        }
        sumChars = "";
        bitString += toConvert[i];
      } else {
        sumChars += toConvert[i];
        string tString = bitset<8>(toConvert[i]).to_string();
        if (tString == "11111111"){ // the ' ' is excluded here
          if ((stoi(sumChars)>255) || (stoi(sumChars)<0)){
            this->withinLimit = false;
            cout << "number out of range: " << sumChars << "\n";
          }
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
    int numCount = 0;
    while(file){
      char c = file.get();
      bool charCheck = false;
      for (int i=0; i<12; i++){
        if (c==this->charList[i] || bitset<8>(c).to_string()=="11111111"){ // get reads in ' 'with bit pattern 11111111
          char ints[11] = {'1','2','3','4','5','6','7','8','9','0',};
          for (int j=0;j<10;j++){
            if (c==ints[j]){
              numCount += 1;
              break;
            }
          }
          charCheck = true;
          break;
        }
      }
      if (charCheck==false){
        this->is09 = false;
        cout << "invalid character found: " << "'" << c <<"'" << "\n";
        break;
      }else{
        fileString += c;
      }
    }
    this->is09 = true;
    file.close();
    cout << "file contains " << numCount << " numbers\n";
    if (numCount<50){
      this->lessThan50 = true;
    } else {this->lessThan50 = false;}
    return fileString;
  }
  bool beget(){
    return this->is09;
  }
};

/*
int main(){
  F2BConverter conv;
  conv.setup("testFile.txt");
  string c = conv.convertFull();
  cout << c << "\n";
  return 0;
}
*/

