#include<bits/stdc++.h>
#include "header_2.h"
#ifndef two
#define two

using namespace std;



class data_2 {
	public:
		int s_no;
		float open_balance,principal,interest_rate,interest;
		float installment,closing_balance;
        float marg_int,bench_int;
}row_2[1000];


 double uniformRandom()
{
  return ( (double)(rand()) + 1. )/( (double)(RAND_MAX) + 1. );
}
 // return a normally distributed random number
double normalRandom()
{
  double u1=uniformRandom();
  double u2=uniformRandom();
  return abs(cos(8.*atan(1.)*u2)*sqrt(-2.*log(u1))); 
}

bool wrong_input_2(float fixed_principal, float  margin_int_rate, float  opening_balance)
{
    if(opening_balance <=0)
    {
        cout<<"Wrong value!!"<<endl;
        return false;
    }

    else if(fixed_principal<=0 )
    {
        cout<<"Wrong value!!"<<endl;
        return false;
    }
    else if(margin_int_rate<=0)
    {
        cout<<"Wrong value!!"<<endl;
        return false;
    }
    else if(fixed_principal > opening_balance)
    {
        cout<<"Wrong set of values for fixed pricipal and opening balance ";
        return false;
    }
    else
    {
        return true;
    }
}

void solve_2()
{
    cout<<endl<<endl;
	float fixed_principal=1000.0,fixed_interest_rate=10.0,opening_balance=12000.0;
	
    //cout<<line()<<"Welcome To Loan EMI calculator";
	cout<<line()<<endl<<endl;
    
    float para_int_rate=0, margin_int_rate=0;
	cout<<"Enter Fixed Principal Amount ($):";
	cin>>fixed_principal;
	
    cout<<"Enter Margin interest Rate (without %): ";
	cin>>margin_int_rate;
    // cout<<"Enter Bechmark interest Rate (Without %): ";
    //cin>>para_int_rate;
	cout<<"Enter Loan Amount ($): ";
	cin>>opening_balance;

    if(wrong_input_2(fixed_principal, margin_int_rate, opening_balance)==false)
    {
        cout<<"Wrong Input set....please check your values!!!"<<endl<<endl;
        return ;
    }
	
    fixed_interest_rate=para_int_rate+margin_int_rate;
    float n=opening_balance/fixed_principal;
    //cout<<"n is "<<n<<endl;
    float months = ceil(n);
    
    cout<<endl;
    cout<<"you have to pay loan for "<<months<<" months !!!!"<<endl;         //here months and years are correct dont change anything
    float interest_rate_in_months=fixed_interest_rate/(1200);
    
    int i=1;	
    while(months>=0)
    { 
      row_2[i].marg_int = margin_int_rate;
      row_2[i].bench_int = normalRandom();
      row_2[i].interest_rate = row_2[i].marg_int + row_2[i].bench_int;
      float x= row_2[i].interest_rate/12.0;
      //cout<<x<<endl;
      row_2[i].s_no = i;
      row_2[i].open_balance = fixed_principal*(months);
      row_2[i].principal = fixed_principal;
      //row_2[i].interest_rate = fixed_interest_rate;
      row_2[i].interest = row_2[i].open_balance*(row_2[i].interest_rate)/1200;
      row_2[i].installment = row_2[i].interest+fixed_principal;
      row_2[i].closing_balance = row_2[i].open_balance-row_2[i].principal;
      
      i++; months--;
      //cout<<"i = "<<i<<endl;
    }
    months=ceil(n);
    cout<<endl<<endl;
    cout<<line()<<"Loan Details with monthly EMI ";
	cout<<line()<<endl<<endl;
    header2();
    for(int i=1;i<=months;i++)
    {   
        cout<<setw(4)<<row_2[i].s_no<<setw(17)
		<<row_2[i].open_balance<<setw(18)
        <<row_2[i].principal<<setw(23)
		<<row_2[i].marg_int<<setw(40)
        <<row_2[i].bench_int<<setw(23)
        <<row_2[i].interest_rate<<setw(18)
		<<row_2[i].interest<<setw(18)
		<<row_2[i].installment<<setw(23)
        <<row_2[i].closing_balance<<endl;
    }

}



#endif