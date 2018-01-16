#include <iostream>
#include <fstream>
#include <string>
#include<vector>

using namespace std;


class Calculator
{
public:
	void calculateTheResult();
	double expression();			//expression which consists of a term or sum of terms //deals with + and -
	double term();				//term which consists of a factor or mul of factors //deals with * and /
	double factor();				//factor which is either a number or an expression


};
