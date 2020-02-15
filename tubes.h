#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
#include <vector>
using namespace std;


void parser(string input, vector<string> &arrLexic);
int getToken(string arrLexic);
string validornot(vector<int> arrToken);


#endif // TUBES_H_INCLUDED
