#include<bits/stdc++.h>

using namespace std;

class data {
	public:
		int s_no;
		float open_balance,principal,interest_rate,interest;
		float installment,closing_balance;
}row[1000];
 
 void header()
 {
 	cout<<setw(4)<<" S.NO"<<setw(20)<<"open balance($)"<<setw(18)<<"principal($)"<<setw(23)
	<<"interest rate(%)"<<setw(18)<<"interest($)"<<setw(18)
	<<"installment($)"<<setw(23)<<"closing balance($)"<<endl;
 }
 char line()
 {
 	for(int i=0;i<30;i++)
 	{
 	   cout<<"*";	
	}
	return '*';
 }
int main()
{   
    cout<<endl<<endl;
	float fixed_principal=1000.0,fixed_interest_rate=10.0,opening_balance=12000.0;
	cout<<line()<<"Welcome To Loan EMI calculator";
	cout<<line()<<endl<<endl;
	
	cout<<"Enter Fixed Principal Amount ($):";
	cin>>fixed_principal;
	cout<<"Enter Fixed interest Rate (without %): ";
	cin>>fixed_interest_rate;
	cout<<"Enter Loan Amount ($): ";
	cin>>opening_balance;
	
    float n=opening_balance/fixed_principal;
    //cout<<"n is "<<n<<endl;
    float months = ceil(n);
    cout<<endl;
    cout<<"you have to pay loan for "<<months<<" months !!!!"<<endl;         //here months and years are correct dont change anything
    float interest_rate_in_months=fixed_interest_rate/(1200);
    int i=1;	
    while(months>=0)
    {
      row[i].s_no = i;
      row[i].open_balance = fixed_principal*(months);
      row[i].principal = fixed_principal;
      row[i].interest_rate = fixed_interest_rate;
      row[i].interest = row[i].open_balance*interest_rate_in_months;
      row[i].installment = row[i].interest+fixed_principal;
      row[i].closing_balance = row[i].open_balance-row[i].principal;
      i++; months--;
      //cout<<"i = "<<i<<endl;
    }
    months=ceil(n);
    cout<<endl<<endl;
    cout<<line()<<"Loan Details with monthly EMI ";
	cout<<line()<<endl<<endl;
    header();
    for(int i=1;i<=months;i++)
    {   
        cout<<setw(4)<<row[i].s_no<<setw(17)
		<<row[i].open_balance<<setw(18)
        <<row[i].principal<<setw(23)
		<<row[i].interest_rate<<setw(18)
		<<row[i].interest<<setw(18)
		<<row[i].installment<<setw(23)
        <<row[i].closing_balance<<endl;
    }

	
	
	
	
}
