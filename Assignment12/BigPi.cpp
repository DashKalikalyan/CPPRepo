#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdio>
#include <iomanip>
#include <mpir.h>
#include <stdlib.h>
#include <string.h>
#include<mpir.h>


using namespace std;

const int MAX_ITERATIONS = 100;
const int PLACES         = 1000;        // desired decimal places
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal
const double ONE_THIRD = 1.0/3.0;
const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size


void cube_root(mpf_t& x, const mpf_t a);

/**
 * Compute the cube root of a positive integer.
 * @param x where to store the result.
 * @param a the number whose cube root to compute.
 */

/**
 * The main.
 */
int main()
{
    mpf_set_default_prec(BIT_COUNT*PRECISION*2);  // precision in bits
	double op1=1.0;
	double op2=3.0;
	unsigned int op3=2;
	unsigned int op4=9;
	int n=0;
	mpf_t x;
	mpf_t b;
	mpf_t y;
	mpf_t z;
	mpf_t t_p_n;
	mpf_t a;
	mpf_t t,u,v,w,p1,rsq,onepr,oneprprsq,nine_r,u_cube,tsq,usq,tu,opspssq,ssq,tsqpusq,oneps,twentyseven,w_into_v,w_into_a,one_minus_w;
	mpf_t tpn_omw,one_minus_r,one_minus_r_sq,one_minus_r_cube,two_u,t_plus_two_u,exp_tuv,r_cube,s_cube;
	//@param p1=2r
	//@param rsq=r^2
	//@param onepr=(1+r)
	//@param oneprprsq=(1+r+r^2)
	//@param nine_r=9*r
	//@param u_cube=(9*r*(1+r+r^2))
	//@param tsq=t^2
	//@param usq=u^2
	//@param tsqpusq=t^2+u^2
	//@param tu=t*u
	//@param ssq=s^2
	//@param opspssq=(1+s+s^2)
	//@param oneps=1+s
	//@param w_into_v=27*(1+s+s^2);
	//@param w_into_a=w*a
	//@param one_minus_w=(1-w)
	//@param t_p_n=3^(2n-1)
	//@param tpn_omw=3^(2n-1)(1-w)
	//@param one_minus_r=(1-r)
	//@param one_minus_r_sq=(1-r)^2
	//@param one_minus_r_cube=(1-r)^3
	//@param two_u=2*u
	//@param t_plus_two_u=(t+2*u)
	//@param exp_tuv=(t+2*u)*v
	//@param s_cube=s^3
	//@param r_cube=(1-s^3)
	mpf_t pi;
	mpf_init(pi);
	mpf_init(t);
    mpf_init(u);
    mpf_init(v);
    mpf_init(w);
    mpf_init(p1);
	mpf_init(rsq);
	mpf_init(onepr);
	mpf_init(oneprprsq);
	mpf_init(nine_r);
	mpf_init(u_cube);
	mpf_init(tsq);
	mpf_init(usq);
	mpf_init(tu);
	mpf_init(ssq);
	mpf_init(opspssq);
	mpf_init(tsqpusq);
	mpf_init(oneps);
	mpf_init(twentyseven);
	mpf_init(w_into_v);
	mpf_init(w_into_a);
	mpf_init(one_minus_w);
	mpf_init(tpn_omw);
	mpf_init(one_minus_r);
	mpf_init(one_minus_r_sq);
	mpf_init(one_minus_r_cube);
	mpf_init(two_u);
	mpf_init(t_plus_two_u);
	mpf_init(exp_tuv);
	mpf_init(r_cube);
	mpf_init(s_cube);
	mpf_init_set_d(x,op1);
	mpf_init_set_d(b,op2);
	mpf_init_set_ui(z,op3);
	mpf_init_set_ui(y,op4);
	mpf_init(a);
	mpf_div(a,x,b);

	mpf_t root_three;
	mpf_init(root_three);

	mpf_sqrt(root_three,b);

	mpf_t root_three_minus_one;
	mpf_init(root_three_minus_one);

	mpf_sub(root_three_minus_one,root_three,x);

	mpf_t root_three_minus_one_by_two;
	mpf_init(root_three_minus_one_by_two);

	mpf_div(root_three_minus_one_by_two,root_three_minus_one,z);
	mpf_t s;
	mpf_init(s);
	mpf_t r;
	mpf_init_set(r,root_three_minus_one_by_two);


	mpf_t r0sq;
	mpf_init(r0sq);

	mpf_t r0_cube;
	mpf_init(r0_cube);

	mpf_t one_minus_r0_cube;
	mpf_init(one_minus_r0_cube);

	mpf_mul(r0sq,r,r);

	mpf_mul(r0_cube,r0sq,r);

	mpf_sub(one_minus_r0_cube,x,r0_cube);

	cube_root(s,one_minus_r0_cube);


	while(n<5)
	{
		mpf_mul_ui(p1,r,op3);
		mpf_add(t,x,p1);
		mpf_mul(rsq,r,r);
		mpf_add(onepr,x,r);
		mpf_add(oneprprsq,onepr,rsq);
		mpf_mul(nine_r,r,y);
		mpf_mul(u_cube,oneprprsq,nine_r);
		cube_root(u,u_cube);
		mpf_mul(tsq,t,t);
		mpf_mul(usq,u,u);
		mpf_mul(tu,t,u);
		mpf_add(tsqpusq,tsq,usq);
		mpf_add(v,tsqpusq,tu);
		mpf_mul(ssq,s,s);
		mpf_add(oneps,x,s);
		mpf_add(opspssq,oneps,ssq);
		mpf_mul(twentyseven,b,y);
		mpf_mul(w_into_v,twentyseven,opspssq);
		mpf_div(w,w_into_v,v);
		mpf_mul(w_into_a,w,a);
		mpf_sub(one_minus_w,x,w);

        if(n==0)
       {

			 mpf_init(t_p_n);
			 mpf_div(t_p_n,x,b);
       }
        else
       {
            double three_p_n=pow(3.0,(2*n-1));
            mpf_init_set_d(t_p_n,three_p_n);

       }

       mpf_mul(tpn_omw,t_p_n,one_minus_w);
       mpf_add(a,w_into_a,tpn_omw);
       mpf_div(pi,x,a);
       mpf_sub(one_minus_r,x,r);
       mpf_mul(one_minus_r_sq,one_minus_r,one_minus_r);
       mpf_mul(one_minus_r_cube,one_minus_r_sq,one_minus_r);
       mpf_mul(two_u,z,u);
       mpf_add(t_plus_two_u,t,two_u);
       mpf_mul(exp_tuv,t_plus_two_u,v);
       mpf_div(s,one_minus_r_cube,exp_tuv);
       mpf_mul(ssq,s,s);
       mpf_mul(s_cube,ssq,s);
       mpf_sub(r_cube,x,s_cube);
       cube_root(r,r_cube);


       n++;

	}


	 FILE *pointer_for_pi;
	 pointer_for_pi=fopen("output_for_big_pi.txt","w");
	 mpf_out_str(pointer_for_pi,BASE,PRECISION+2,pi);
	 fclose(pointer_for_pi);



	    ifstream in_stream;
	    in_stream.open("output_for_big_pi.txt");
	    string output;
	    in_stream>>output;
	    in_stream.close();

	    ofstream out_stream;
	    out_stream.open("formatted_output_for_big_pi.txt");


	    int i=2;
	    while(i<(PLACES+3))
	    {
	    		if((i-3)%(LINE_SIZE*GROUP_SIZE)==0 && i!=3)
	    		{
	    			out_stream<<"\n\n"<<"  ";
	    		}

	    		else if((i-3)%(LINE_SIZE)==0 && i!=3)
	    		{
	    			out_stream<<"\n"<<"  ";
	    		}

	    		else 	if((i-3)%(BLOCK_SIZE)==0 && i!=3)
	    		{
	    			out_stream<<" ";
	    		}

	    		out_stream<<output[i];

	    		if(i==2)
	    		{
	    			out_stream<<".";
	    		}
	    		i++;
	    }


	    out_stream.close();



    return 0;
}





void cube_root(mpf_t& x, const mpf_t a)
{
	mpf_t ONE,TWO,THREE;
	mpf_init_set_d(ONE,1.0);
	mpf_init_set_d(TWO,2.0);
	mpf_init_set_d(THREE,3.0);

	mpf_set_d(x,1.0);

	mpf_t x_sq,a_by_x_sq,two_x,abxsq_p_twox;
	mpf_init(x_sq);
	mpf_init(a_by_x_sq);
	mpf_init(two_x);
	mpf_init(abxsq_p_twox);

	for(int i=0;i<99;i++)
	{
		mpf_mul(x_sq,x,x);
		mpf_div(a_by_x_sq,a,x_sq);
		mpf_mul(two_x,TWO,x);
		mpf_add(abxsq_p_twox,a_by_x_sq,two_x);
		mpf_div(x,abxsq_p_twox,THREE);

	}


}

