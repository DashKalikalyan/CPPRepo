#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void compute_primes(int [],int);								//function that computes the positions where prime numbers will occur
void print_primes(bool [],int [],int);							//function that prints the values of the prime numbers

const int MAX_NUMBER = 1000;  // maximum possible prime number
const int ROW_SIZE   = 20;    // row size for printing

/***** Complete this program. *****/

/**
 * The main: Compute and print the prime numbers up to MAX_NUMBER.
 */
int main()
{
   int primeNumbers[MAX_NUMBER];
	int n=MAX_NUMBER;
	compute_primes(primeNumbers,MAX_NUMBER);
	return 0;
}

void compute_primes(int primeNumbers[],int n)

{
	bool primeOrNot[n];
	memset(primeOrNot,1,n);                                      //sets the value of each element of array to true
	
	for(int p=2;p*p<=n;p++)
	{
		if(primeOrNot[p]==true)
			{
				for(int i=p*2;i<=n;i=i+p)
				{
					primeOrNot[i]=false;						//sets the value of multiples to false hence making them composite number
				
				}
			
			
			}
	
	
	}
    
    print_primes(primeOrNot,primeNumbers,n);					//function call to print the prime numbers
}

void print_primes(bool primeOrNot[],int primeNumbers[],int n)
{
	int i=0;
	for(int p=2;p<=n;p++)
	{  
	    if(primeOrNot[p])
	    {
		    primeNumbers[i]=p;
		    cout<<setw(4)<<primeNumbers[i]<<" ";
		    i++;
		    if((i)%ROW_SIZE==0)
		    cout<<endl;
		    
	    }
	    
	}
	
	cout<<endl<<endl<<"Done!";
	

}

