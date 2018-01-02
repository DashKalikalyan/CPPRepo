#include "RomanNumeral.h"
using namespace std;

RomanNumeral::RomanNumeral() : roman(""), decimal(0)
{
}

/***** Complete this class implementation. *****/
RomanNumeral::RomanNumeral(int x)
{
   decimal=x;
   to_roman(decimal);
}

RomanNumeral::RomanNumeral(string y)
{
   roman=y;
   to_decimal(roman);
}

void RomanNumeral::to_roman(int number)
{
	string temp;
	while(number!=0)
	{
		int how_many_1000=number/1000;

		while(how_many_1000 > 0)
		{
			temp=temp+"M";
			how_many_1000--;
		}

		number=number%1000;

		int how_many_900=number/900;

		if(how_many_900>0)
		{
			temp=temp+"CM";
			how_many_900--;
		}

		number=number%900;

		int how_many_500=number/500;

		if(how_many_500>0)
		{
			temp=temp+"D";
			how_many_500--;
		}

		number=number%500;

		int how_many_400=number/400;

		if(how_many_400>0)
		{
			temp=temp+"CD";
			how_many_400--;
		}

		number=number%400;

		int how_many_100=number/100;

		while(how_many_100>0)
		{
			temp=temp+"C";
			how_many_100--;
		}

		number=number%100;

		int how_many_90=number/90;

		if(how_many_90>0)
		{
			temp=temp+"XC";
			how_many_90--;
		}

		number=number%90;

		int how_many_50=number/50;

		if(how_many_50>0)
		{
			temp=temp+"L";
			how_many_50--;
		}

		number=number%50;

		int how_many_40=number/40;

		if(how_many_40>0)
		{
			temp=temp+"XL";
			how_many_40--;
		}

		number=number%40;

		int how_many_10=number/10;

		while(how_many_10>0)
		{
			temp=temp+"X";
			how_many_10--;
		}

		number=number%10;

		int how_many_9=number/9;

		if(how_many_9>0)
		{
			temp=temp+"IX";
			how_many_9--;
		}

		number=number%9;

		int how_many_5=number/5;

		if(how_many_5>0)
		{
			temp=temp+"V";
			how_many_5--;
		}

		number=number%5;

		int how_many_4=number/4;

		if(how_many_4>0)
		{
			temp=temp+"IV";
			how_many_4--;
		}

		number=number%4;

		int how_many_1=number/1;

		while(how_many_1>0)
		{
			temp=temp+"I";
			how_many_1--;
		}

		number=number%1;






	}

	roman=temp;




}




void RomanNumeral::to_decimal(string str)
{
	int temp=0;
	int i=0;
	while(i<str.length())
	{
		if(str[i]=='M')
			temp+=1000;

		if(str[i]=='D')
			temp+=500;

		if(str[i]=='C')
		{
			if(str[i+1]=='D')
			{
				temp+=400;
				i++;
			}
			else if (str[i+1]=='M')
			{
				temp+=900;
				i++;
			}
			else
			temp+=100;
		}

		if(str[i]=='L')
			temp+=50;

		if(str[i]=='X')
		{
			if(str[i+1]=='L')
			{
				temp+=40;
				i++;
			}
			else if(str[i+1]=='C')
			{
				temp+=90;
				i++;
			}
			else

			temp+=10;
		}

		if(str[i]=='V')
			temp+=5;

		if(str[i]=='I')
		{
			if(str[i+1]=='V')
			{
				temp+=4;
				i++;
			}
			else if(str[i+1]=='X')
			{
				temp+=9;
				i++;
			}
			else

			temp+=1;
		}




	i++;


	}

	decimal=temp;
}



ostream& operator <<(ostream& dout, RomanNumeral& r)
{
   dout<<"["<<r.decimal<<":"<<r.roman<<"]";
   return dout;
}



istream& operator >>(istream& in, RomanNumeral& r)
{


	in>>r.roman;

	r.to_decimal(r.roman);

	return(in);
}



RomanNumeral operator+(RomanNumeral x,RomanNumeral y)
{
	RomanNumeral temp;
	temp.decimal=x.decimal+y.decimal;
	temp.to_roman(temp.decimal);
	return(temp);

}

RomanNumeral operator-(RomanNumeral x,RomanNumeral y)
{
	RomanNumeral temp;
	temp.decimal=x.decimal-y.decimal;
	temp.to_roman(temp.decimal);
	return(temp);

}

RomanNumeral operator*(RomanNumeral x,RomanNumeral y)
{
	RomanNumeral temp;
	temp.decimal=x.decimal*y.decimal;
	temp.to_roman(temp.decimal);
	return(temp);

}

RomanNumeral operator/(RomanNumeral x,RomanNumeral y)
{
	RomanNumeral temp;
	temp.decimal=x.decimal/y.decimal;
	temp.to_roman(temp.decimal);
	return(temp);

}

bool operator==(RomanNumeral x,RomanNumeral y)
{
	bool temp=false;
	if(x.decimal==y.decimal)
		temp=true;
	return(temp);

}

bool operator!=(RomanNumeral x,RomanNumeral y)
{
	bool temp=false;
	if(x.decimal!=y.decimal)
		temp=true;
	return(temp);

}