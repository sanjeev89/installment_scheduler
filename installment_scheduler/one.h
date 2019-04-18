#include<bits/stdc++.h>
#include<fstream>
#include "header_1.h"
#ifndef one
#define one

using namespace std;

class data {
	public:
		string date;
		float open_balance,principal,interest_rate,interest;
		float installment,closing_balance;
}row[1000];

bool wrong_input_1(float fixed_principal,float fixed_interest_rate, float opening_balance)
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
    else if(fixed_interest_rate<=0)
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

void solve_1()
{
    cout<<endl<<endl;
	float fixed_principal=1000.0,fixed_interest_rate=10.0,opening_balance=12000.0;
	//cout<<line()<<"Welcome To Loan EMI calculator";
	//cout<<line()<<endl<<endl;
	
	cout<<"Enter Fixed Principal Amount ($):";
	cin>>fixed_principal;
	cout<<"Enter Fixed interest Rate (without %): ";
	cin>>fixed_interest_rate;
	cout<<"Enter Loan Amount ($): ";
	cin>>opening_balance;
	if(wrong_input_1(fixed_principal, fixed_interest_rate, opening_balance) == false )
    {
        cout<<" wrong input set!!!!"<<endl<<endl;
        return ;
    }
    float n=opening_balance/fixed_principal;
    //cout<<"n is "<<n<<endl;
    float months = ceil(n);
    cout<<endl;
   
   //=============================
   //     file handling start
  //==============================
   
    ofstream fout;
    fout.open("out.csv", ios::app);
    fout<<"Fixed Principal Amount ($): "<<","<<fixed_principal<<endl;
    fout<<"Fixed interest Rate :"<<","<<fixed_interest_rate<<" %"<<endl;
	fout<<" Loan Amount ($): "<<","<<opening_balance<<endl;
    fout<<"months "<<","<<months<<endl;

        //enter header file handling
    fout<<"           next due"<<","<<"open balance($)"<<","<<"principal($)"
	<<","<<"interest rate(%)"<<","<<"interest($)"
	<<","<<"installment($)"<<","<<"closing balance($)"<<endl;
    //header end

   //=============================
   //     file handling end
  //==============================



  //===============================
  //        timing control starts
  //==============================

   	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
    int month = timePtr->tm_mon+1;
    int year = timePtr->tm_year+1900;
    cout<<"month "<<timePtr->tm_mon<<" year "<<timePtr->tm_year<<endl;

  //===============================
  //        timing control ends
  //===============================

    cout<<"you have to pay loan for "<<months<<" months !!!!"<<endl;         //here months and years are correct dont change anything
    float interest_rate_in_months=fixed_interest_rate/(1200);
    int i=1;	
    while(months>=0)
    {
      row[i].date = to_string(month)+"-"+to_string(year);
      row[i].open_balance = fixed_principal*(months);
      row[i].principal = fixed_principal;
      row[i].interest_rate = fixed_interest_rate;
      row[i].interest = row[i].open_balance*interest_rate_in_months;
      row[i].installment = row[i].interest+fixed_principal;
      row[i].closing_balance = row[i].open_balance-row[i].principal;
      i++; months--;
      month++;
      if(month>12)
      {
          month = 1;
          year = year+1;
      }
      //cout<<"i = "<<i<<endl;
    }
    months=ceil(n);
    cout<<endl<<endl;
    //cout<<line()<<"Loan Details with monthly EMI ";
	//cout<<line()<<endl<<endl;
    header1();

    for(int i=1;i<=months;i++)
    {   
        cout<<setw(20)<<row[i].date<<setw(17)
		<<row[i].open_balance<<setw(18)
        <<row[i].principal<<setw(23)
		<<row[i].interest_rate<<setw(18)
		<<row[i].interest<<setw(18)
		<<row[i].installment<<setw(23)
        <<row[i].closing_balance<<endl;

        //enter rows in file
        fout<<setw(4)<<row[i].date<<setw(17)<<","
		<<row[i].open_balance<<setw(18)<<","
        <<row[i].principal<<setw(23)<<","
		<<row[i].interest_rate<<setw(18)<<","
		<<row[i].interest<<setw(18)<<","
		<<row[i].installment<<setw(23)<<","
        <<row[i].closing_balance<<endl;

        //end
    }
    fout.close();
}

#endif
