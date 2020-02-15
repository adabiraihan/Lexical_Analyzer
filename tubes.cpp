#include "tubes.h"

void parser(string input, vector<string> &arrLexic){
  string kata="";
  for (int i=0; i<input.length(); i++) {
    if (input[i]==' ') {
      if (input[i-1] !='(' && input[i-1]!=')')
      {
        arrLexic.push_back(kata);
        kata="";
      }
    }else if (input[i]=='(') {
      if (kata != "") {
        arrLexic.push_back(kata);
        kata="";
      }
    arrLexic.push_back(string(1,input[i]));
    }else if (input[i]==')') {
      if (kata != "") {
        arrLexic.push_back(kata);
        kata="";
      }
    arrLexic.push_back(string(1,input[i]));
    }else{
      kata=kata + input[i];
    }
  }
  if (kata!="") {
    arrLexic.push_back(kata);
  }
}

int getToken(string arrLexic){
  switch (arrLexic.length()){
    case 1:
      if (arrLexic[0]=='p' || arrLexic[0]=='q' || arrLexic[0]=='r' || arrLexic[0]=='s') {
        return 1;
      }else if (arrLexic[0]=='(') {
        return 9;
      }else if (arrLexic[0]==')') {
        return 10;
      }
    case 2:
      if (arrLexic[0]=='o' && arrLexic[1]=='r') {
        return 4;
      }else if (arrLexic[0]=='i' && arrLexic[1]=='f') {
        return 6;
      }
    case 3:
      if(arrLexic[0]=='n' && arrLexic[1]=='o' && arrLexic[2]=='t'){
        return 2;
      }else if(arrLexic[0]=='a' && arrLexic[1]=='n' && arrLexic[2]=='d'){
        return 3;
      }else if (arrLexic[0]=='x' && arrLexic[1]=='o' && arrLexic[2]=='r') {
        return 5;
      }else if (arrLexic[0]=='i' && arrLexic[1]=='f' && arrLexic[2]=='f'){
        return 8;
      }
    case 4:
      if (arrLexic[0]=='t' && arrLexic[1]=='h' && arrLexic[2]=='e' && arrLexic[3]=='n') {
        return 7;
      }
    default:
      return 0;
  }
}


string validornot(vector<int> arrToken){
    vector<int> stackToken;
    char state = '1';
    for (int i = 0; i < arrToken.size(); i++) {
      switch (arrToken[i]) {
        case 0:
          return "TIDAK VALID";
          break;
        case 1:
          if (state == '1') {
            state = '2';
          }else if (state == '2') {
            stackToken.push_back(1);
          }
          break;
        case 2:
          if (!(arrToken[i+1] == 1 || arrToken[i+1] == 9)) {
            return "TIDAK VALID";
          }
          break;
        case 3:
          if (state == '2' && (arrToken[i+1] == 1 || arrToken[i+1] == 2 || arrToken[i+1] == 9)) {
              state = '1';
          }else{
            return "TIDAK VALID";
          }
          break;
        case 4:
          if (state == '2' && (arrToken[i+1] == 1 || arrToken[i+1] == 2 || arrToken[i+1] == 9)) {
            state = '1';
          }else{
            return "TIDAK VALID";
          }
          break;
        case 5:
          if (state == '2' && (arrToken[i+1] == 1 || arrToken[i+1] == 2 || arrToken[i+1] == 9)) {
            state = '1';
          }else{
            return "TIDAK VALID";
          }
          break;
        case 6:
          if (state == '1') {
            stackToken.push_back(6);
          }
          break;
        case 7:
          if (state == '2') {
            if (stackToken.back()==6) {
                state = '1';
                stackToken.pop_back();
            }
          }
          break;
        case 8:
          if (state == '2' && (arrToken[i+1] == 1 || arrToken[i+1] == 2 || arrToken[i+1] == 9)) {
            state = '1';
          }else{
            return "TIDAK VALID";
          }
          break;
        case 9:
          if (state == '1') {
            stackToken.push_back(9);
          }
          break;
        case 10:
          if (state == '2') {
            if (stackToken.back()==9) {
              stackToken.pop_back();
            }
          }
          break;
      }
    }
    if (stackToken.size()==0 && state == '2') {
      return "VALID";
    }else{
      return "TIDAK VALID";
    }
}

