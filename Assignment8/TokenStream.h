#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include"Token.h"

using namespace std;

class TokenStream
{
	bool isTheValueSaved;
	Token valueSavedHere;
public:
	TokenStream();
	Token getTheValue();
	void ungetTheValue(Token t);
};

