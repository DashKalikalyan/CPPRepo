#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include"TokenStream.h"


using namespace std;

TokenStream :: TokenStream():valueSavedHere(0)
{
	isTheValueSaved=0;


}

void TokenStream :: ungetTheValue(Token t)
{
	isTheValueSaved=true;
	valueSavedHere=t;
}

Token TokenStream :: getTheValue()
{
	if(isTheValueSaved)
	{
		isTheValueSaved=false;
		return valueSavedHere;
	}

	char ch;
	cin>>ch;
	switch(ch)
	{
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case ';':
		case '=':
			return Token(ch);
		case '.':
			{
				cout<<"Done!";
				std::exit(0);
			}
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			cin.unget();
			double value;
			cin>>value;
			return Token('$',value);
		}


			/*
			 * here the default value is set
			 */
	}
}
