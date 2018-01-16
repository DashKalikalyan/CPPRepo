#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include"Token.h"

using namespace std;




/*
 * Constructor for + - * / ( and )
 */
Token :: Token(char ch)
{
	kindOfTheToken=ch;
	valueOfTheToken=0;
}

/*
 * constructor for all the digits
 */
Token ::Token(char ch, double value)
{
	kindOfTheToken=ch;
	valueOfTheToken=value;
}
