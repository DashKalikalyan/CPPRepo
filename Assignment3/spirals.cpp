#include <iostream>
#include <iomanip>

using namespace std;


const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number

/***** Complete this program. *****/

void do_spiral(const int n, const int start);

void make_spiral(int [][MAX_SIZE],int,int);
/*the above function makes the spiral pattern in the array*/

void print_spiral(int [][MAX_SIZE],int,int);
/*the above function prints the desired output after creation of the spiral*/

/**
 * The main: Generate and print spirals of various sizes.
 */
int main()
{
    do_spiral(1, 1);
    do_spiral(5, 1);
    do_spiral(9, 11);
    do_spiral(12, 13);
    do_spiral(15, 17);
}

void do_spiral(const int n,const int start)
{

	int A[MAX_SIZE][MAX_SIZE];
	
	if(start<1 || start>50)
	
	{
		print_spiral(A,n,start);    //calls print_spiral function to get the output required for starting values which are less than 0 or greater than 50
	}
	
    else if(n%2==0)
    {
        print_spiral(A,n,start);   //calls print_spiral function to get  the output required for even size array
    }
 
    else
    {
		make_spiral(A,n,start); //calls the make_spiral function to create the spiral
    }

	

}


void make_spiral(int A[][MAX_SIZE],int n,int startingPoint)

{
    
    
    int limit=startingPoint+(n*n)-1;
	int p=(n-1)/2;                            //sets the starting position where we should place the start number
	int q=(n-1)/2;							  //sets the starting position where we should place the start number
	A[p][q]=startingPoint;                    //gives value to the central position
	int i,j,k;
	int start=startingPoint;
    

	for(k=1;k<=n;k++)     						
	{
	    for(j=1;j<=k;j++)                          				//loop that sets the value of the elements to the same row but diff column
		{
			if(k%2==0)											//decrease in the column number as k is even
			{
			    if(startingPoint+j <=limit)
			    {
				    A[p][q-j]=startingPoint+j;           		//increase the value of element in the same row but next column to the left by 1
			    }
			
			}
			else												//increase in the column number as k is odd
			{
			     if(startingPoint+j <=limit)
			     {
				    A[p][q+j]=startingPoint+j;          		//increase the value of element in the same row but next column to the right by 1
			     }
			}
			
		}
		
		startingPoint=startingPoint+k;							//sets the startingPoint to the new location 
		
		if(k%2==0)
			q=q-k;
		else
			q=q+k;
	
		for(i=1;i<=k;i++)                     					//loop that sets the value of the elements to the same column but diff row
		{
			if(k%2==0)											//increase in the row number as k is even
			{
			     if(startingPoint+i <=limit)
			     {
				    A[p+i][q]=startingPoint+i;					//increase the value of element in the same column but next row to the down by 1
			     }
			
			}
			else												//decrease in the row number as k is odd
			{
			    if(startingPoint+i <=limit)
			     {
				    A[p-i][q]=startingPoint+i;					//increase the value of element in the same column but next row to the up by 1
			     }
			}
			
			
		}

		startingPoint=startingPoint+k;							//sets the startingPoint to the new location
		
		if(k%2==0)
			p=p+k;
		else
			p=p-k;
    }
   
	print_spiral(A,n,start);									//calls the print function to print the spiral
}









void print_spiral(int A[][MAX_SIZE],int n,int start)
{
	
	cout<<"Spiral of size "<<n<<" starting at "<<start<<endl;
	
	if(start<1 || start>50)
	
	{
        cout<<"***** Error: Starting value 0 < 1 or > 50"<<endl<<endl; 
	}
	

    else if(n%2==0)
    {
        
        cout<<"***** Error: Size "<<n<<" must be odd."<<endl<<endl;
    }
	else
	{
	    cout<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
			cout<<setw(4)<<A[i][j];
				
			}
			cout<<"\n";
		}
		cout<<endl;

	}


}
	
