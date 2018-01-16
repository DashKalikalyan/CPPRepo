#include <iostream>
#include <fstream>
#include <string>
#include<vector>

using namespace std;

class Token
{
public:
	char kindOfTheToken;
	double valueOfTheToken;
	Token(char ch);
	Token(char ch, double value);

};
