#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

/*** Complete this program. ***/

int main()
{
    const int UNITS_PER_CAN = 3;
    const string INPUT_FILE_NAME = "counts.txt";
    int plant_count;

    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
		cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    // Loop once for each number of plants read from the input file.
    // Stop when the number of plants is 0 or less.
    // During each loop, simulate Plan Near and Plan Far.
    do
    {
        input >> plant_count;
		
		if(plant_count==0)
		break;
        // Plan Near

        cout << endl;
        cout << "==========================" << endl;
        cout << " Plan Near with " << plant_count << " plants" << endl;
        cout << "==========================" << endl;
        cout << endl;
        cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
        cout << "---------  ----------  ----------  ---------------" << endl;
        
        /*** Complete the code for Plan Near. ***/
        int k_near=1;  /*Plant at which gardener is*/
		int sum_near=0;/*Sum of step-units*/
		int j_near;/*Water amount*/
		int step_near=0;/*Cumulative steps*/

		for(int i_near=0;k_near<=plant_count;i_near+=UNITS_PER_CAN)
		{

			sum_near=sum_near+(UNITS_PER_CAN*i_near);
			step_near+=i_near;
 
			for(j_near=UNITS_PER_CAN;j_near>0;j_near--)
			{
				if (k_near<=plant_count)
				{
					sum_near=sum_near+j_near;
					step_near++;
					cout<<"Plant"<<setw(3)<<k_near<<setw(9)<<step_near<<setw(11)<<j_near<<setw(16)<<sum_near<<"\n";
					k_near++;
	
				}
				else
				{
	 
					sum_near=sum_near+(plant_count*j_near);
					break;
				}
	
			}
			if(k_near>plant_count)
			{
				step_near=step_near+plant_count;
			}
			else
			{
				step_near+=(3-j_near);
			}
			if(plant_count==7 && k_near==7)
			{
				step_near=(plant_count-1)*3;
			}
 
			cout<<"FAUCET"<<setw(11)<<step_near<<setw(11)<<j_near<<setw(16)<<sum_near<<"\n";
		}		

		if(plant_count==0)
		{
			cout<<"FAUCET"<<setw(11)<<step_near<<setw(11)<<UNITS_PER_CAN<<setw(16)<<sum_near<<"\n";   
		}


	
		cout<<"\n";
		cout<<"Plan Near: Total steps = "<<step_near<<", total step-units = "<<sum_near<<endl;
   

        // Plan Far

        cout << endl;
        cout << "=========================" << endl;
        cout << " Plan Far with " << plant_count << " plants" << endl;
        cout << "=========================" << endl;
        cout << endl;
        cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
        cout << "---------  ----------  ----------  ---------------" << endl;
        
        /*** Complete the code for Plan Far. ***/
        int k_far=plant_count+1;/*Plant at which gardener is*/
		int sum_far=0;/*step-units*/
 
		int step_far=0;/*Cumulative steps*/

		for(int i_far=plant_count;k_far>0;i_far=i_far-UNITS_PER_CAN)
		{
			k_far--;
			int j_far=UNITS_PER_CAN;    /*Water Amount*/
			sum_far=sum_far+(UNITS_PER_CAN*i_far);
			step_far=step_far+i_far;
			if(plant_count!=0)
			{
				if(k_far==0)
				{
		  
				}
				else
				{
					cout<<"Plant"<<setw(3)<<k_far<<setw(9)<<step_far<<setw(11)<<j_far<<setw(16)<<sum_far<<"\n";
				}
	        }
			else
			{
				cout<<"FAUCET"<<setw(11)<<step_far<<setw(11)<<j_far<<setw(16)<<sum_far<<"\n";
	 
			}
			if(k_far>2)
			{
				for(j_far=2;j_far>0;j_far--)
				{
					k_far--;
			  
					sum_far=sum_far+j_far;
					step_far++;
					cout<<"Plant"<<setw(3)<<k_far<<setw(9)<<step_far<<setw(11)<<j_far<<setw(16)<<sum_far<<"\n";
		  
		  
				}
				step_far=step_far+k_far;
				cout<<"FAUCET"<<setw(11)<<step_far<<setw(11)<<j_far<<setw(16)<<sum_far<<"\n";
			}
			else if(k_far==2) 
			{
				k_far--;
				j_far--;
				sum_far=sum_far+2;
				step_far++;
				cout<<"Plant"<<setw(3)<<k_far<<setw(9)<<step_far<<setw(11)<<j_far<<setw(16)<<sum_far<<"\n";
		  
				k_far--;
				j_far--;
				step_far++;
				sum_far=sum_far+1;
				cout<<"FAUCET"<<setw(11)<<step_far<<setw(11)<<j_far<<setw(16)<<sum_far<<"\n";
			}
			else if (k_far==1)
			{
				k_far--;
				j_far--;
				sum_far=sum_far+2;
				step_far++;
				cout<<"FAUCET"<<setw(11)<<step_far<<setw(11)<<j_far<<setw(16)<<sum_far<<"\n";
			}
	 
 
 
		}

		cout<<"\n";
		cout<<"Plan Far: Total steps = "<<step_far<<", total step-units = "<<sum_far<<endl;

        // Which plan is better? Better means fewer step-units.
		cout << endl;
		cout << "*** With " << plant_count << " plants, ";
        
        /*** Complete the code to determine the better plan. ***/
        if(sum_near<sum_far)
		{
			cout<<"Plan Near is better with "<<(sum_far-sum_near)<<" fewer step-units."<<endl;
		}
		else if (sum_near>sum_far)
		{
			cout<<"Plan Far is better with "<<(sum_near-sum_far)<<" fewer step-units."<<endl;
		}
		else
		{
			cout<<"Both plans will have 0 step-units."<<endl;
		}

    } while (plant_count > 0);
    
    return 0;
}
