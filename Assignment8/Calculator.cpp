#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include"Calculator.h"
#include"TokenStream.h"

using namespace std;

TokenStream tokenStreamObject;

/*
 * factor function which checks the expression or the number
 */
double Calculator::factor()
{
	Token t=tokenStreamObject.getTheValue();
	switch(t.kindOfTheToken)
	{
		case '(':
		{
			double d=expression();
			t=tokenStreamObject.getTheValue();
			return d;

		}
		case '$':
			return t.valueOfTheToken;

	}
}

/*
 * term function does the multiplication and division of all the factors
 */

double Calculator::term()
{
	double leftValue= factor();
	while(true)
	{
		Token t=tokenStreamObject.getTheValue();
		switch(t.kindOfTheToken)
		{
			case'*':
				leftValue*=factor();
				break;
			case'/':
			{
				double d=factor();
				if(d==0)
				{
					cout<<("***** Division by zero");
				}
				else
					leftValue/=d;
				break;
			}
			default:
				tokenStreamObject.ungetTheValue(t);
				return leftValue;
		}

	}
}

/*
 * expression function does addition and subtraction of all the terms
 */

double Calculator::expression()
{
	double leftValue= term();
	while(true)
	{

		Token t=tokenStreamObject.getTheValue();
		switch(t.kindOfTheToken)
		{
			case'+':
				leftValue+=term();
				break;
			case'-':
				leftValue-=term();
				break;
			default:
				tokenStreamObject.ungetTheValue(t);
				return leftValue;

		}
	}
}





void Calculator:: calculateTheResult()
{
	while(true)
	{
		cout<<"Expression? ";
		Token t=tokenStreamObject.getTheValue();
		while (t.kindOfTheToken == '=')
		{
			t=tokenStreamObject.getTheValue();
		}
		tokenStreamObject.ungetTheValue(t);
		cout<<expression()<<endl<<endl;


	}
}
