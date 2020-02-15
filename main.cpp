#include <iostream>
#include <vector>
#include "tubes.h"


using namespace std;

int main(){
  string input="";
  vector<string> arrLexic;
  vector<int> arrToken;
  int token;
  cout<<"============================================"<<endl;
  cout<<"========= Program Lexical Analyzer ========="<<endl;
  cout<<"============================================"<<endl;
  cout<<"Input 'selesai' untuk mengakhiri program!"<<endl<<"Input : ";
  getline(cin, input);
  cout<<"============================================"<<endl;
  while (input != "selesai") {

    parser(input,arrLexic);
    cout<<"Token : ";
    for (int i=0; i<arrLexic.size();i++){
      token = getToken(arrLexic[i]);
      if (token!=0) {
        arrToken.push_back(token);
        cout<<token<<" ";
      }else{
        arrToken.push_back(token);
        cout<<"error";
        i=arrLexic.size();
      }
    }
    cout<<endl<<validornot(arrToken)<<endl<<endl;
    arrLexic.clear();
    arrToken.clear();
    cout<<"============================================"<<endl;
    cout<<"============================================"<<endl;
    cout<<"Input 'selesai' untuk mengakhiri program!"<<endl<<"Input : ";
    getline(cin, input);
    cout<<"============================================"<<endl;
  }
  return 0;
}




