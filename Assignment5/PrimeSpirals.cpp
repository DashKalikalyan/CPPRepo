#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

const int MAX_START = 50;   // maximum starting number

/***** Complete this program. *****/

void do_prime_spiral(const int n, const int start);

void print_spiral(vector<int>& A,int,int [],int);
//function to print the spiral
int	check_prime(int,int [],int);
//function to check the number is prime or composite
int compute_primes(int [],int);
//function to compute the list of prime numbers between starting point and last number

/**
 * The main: Generate and print prime spirals of various sizes.
 */
int main()
{
    do_prime_spiral(5, 1);
    do_prime_spiral(25, 11);
    do_prime_spiral(35, 0);
    do_prime_spiral(50, 31);
    do_prime_spiral(101, 41);
}

int compute_primes(int primeNumbers[],int n)
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
	int i=0;
	for(int p=2;p<=n;p++)
	{  
	    if(primeOrNot[p])
	    {
		    primeNumbers[i]=p;

		    i++;

		    
	    }
	    
	}
return(i);														//returns the no of prime numbers avaible in the list
    
}






void do_prime_spiral(const int n,const int start)
{
	int limit=start+(n*n)-1;
	int p=(n-1)/2;												//sets the starting position where we should place the start number
	int q=(n-1)/2;												//sets the starting position where we should place the start number
	vector<vector<int>> A(n, vector<int>(n));					//vector of vector
	int startingPoint=start;
	A[p][q]=startingPoint;										//gives value to the central position
	int primeNumbers[limit];
	int i,j,k;
	
	if(start<1 || start>50)
	{
		cout<<"Prime spiral of size "<<n<<" starting at "<<start<<endl;
        cout<<"***** Error: Starting value 0 < 1 or > 50"<<endl<<endl; 
	}
	

    else if(n%2==0)
    {
        cout<<"Prime spiral of size "<<n<<" starting at "<<start<<endl;
        cout<<"***** Error: Size "<<n<<" must be odd."<<endl<<endl;
    }
 

    else


   {
	   int no_of_elements_in_compute_primes= compute_primes(primeNumbers,limit);

       cout<<"Prime spiral of size "<<n<<" starting at "<<start<<endl<<endl;

	for(k=1;k<=n;k++)
	{
	    for(j=1;j<=k;j++)														//loop that sets the value of the elements to the same row but diff column
		{
			if(k%2==0)															//decrease in the column number as k is even
			{
			    if(startingPoint+j <=limit)
			    {
				    A[p][q-j]=startingPoint+j;									//increase the value of element in the same row but next column to the left by 1
			    }
			
			}
			else																//increase in the column number as k is odd
			{
			     if(startingPoint+j <=limit)
			     {
				    A[p][q+j]=startingPoint+j;									//increase the value of element in the same row but next column to the right by 1
			     }
			}
			
		}
		startingPoint=startingPoint+k;											//sets the startingPoint to the new location
		if(k%2==0)
		q=q-k;
		else
		q=q+k;
	
	for(i=1;i<=k;i++)															//loop that sets the value of the elements to the same column but diff row
		{
			if(k%2==0)															//increase in the row number as k is even
			{
			     if(startingPoint+i <=limit)
			     {
				    A[p+i][q]=startingPoint+i;									//increase the value of element in the same column but next row to the down by 1
			     }
			
			}
			else																//decrease in the row number as k is odd
			{
			    if(startingPoint+i <=limit)
			     {
				    A[p-i][q]=startingPoint+i;									//increase the value of element in the same column but next row to the up by 1
			     }
			}
			
			
		}

		startingPoint=startingPoint+k;											//sets the startingPoint to the new location
		if(k%2==0)
		p=p+k;
		else
		p=p-k;
   }
   for(int x=0;x<n;x++)

{	
	print_spiral(A[x],n,primeNumbers,no_of_elements_in_compute_primes);			//calls the print function to print the spiral
	cout<<"\n";
}
cout<<endl;
   
   }


}

void print_spiral(vector<int>& A,int n,int primeNumbers[],int no_of_elements_in_compute_primes)
{

	{
   for(int i=0;i<n;i++)
	{
		
		if(A[i]==1)
					cout<<".";
				else if(check_prime(A[i],primeNumbers,no_of_elements_in_compute_primes)==1)      //function call to check the number is prime or not
					cout<<"#";
				else
					cout<<".";
		
	}

	}
}




int	check_prime(int prime,int primeNumbers[],int no_of_elements_in_compute_primes)
{
    int flag=0;
	
	for(int i=0; i<no_of_elements_in_compute_primes; i++)
    {
        
        if (prime==primeNumbers[i])
			flag=1;
		
    }
	return(flag);
}
	
