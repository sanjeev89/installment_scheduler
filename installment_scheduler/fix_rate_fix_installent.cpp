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
          //   PMT/PV = r.(1 + 1/(1+r)^n -1)
 void complete_four_PMT(float &PMT, float &PV, float &r, int &n)
 {     
        
        if(PMT==0.0)
        PMT = (PV*r/100.0)*(1 + 1/(pow(1+r/100.0, n)-1));
        cout<<"PMT "<<PMT<<endl;
 }

 void complete_four_PV(float &PMT, float &PV, float &r, int &n)
 {    
      if(PV==0.0)
      PV = PMT/((r/100.0)*(1 + 1/(pow(1+r/100.0, n)-1)));
      cout<<"PV "<<PV<<endl;
 }

  void complete_four_r(float &PMT, float &PV, float &r, int &n)
 {
        if(r==0.0)
        {
        	
		}
 }

  void complete_four_n(float &PMT, float &PV, float &r, int &n)
 {     
        if(n!=0)
        return ;
        float xx = (PMT/(PV*r/100.0))-1;
        cout<<"x : "<<xx<<endl;
        float yy = 1.0/xx;
        cout<<"yy : "<<yy<<endl;
        float zz = yy+1;
        cout<<"zz : "<<zz<<endl;
        float r1 = (r/100.0)+1;
        cout<<"r1 : "<<r1<<endl;
        float temp=r1;
        int count = 1;
        while(temp < zz)
        {
             temp=temp*r1;
             count++;
        }

        n = count;
        cout<<"n "<<n<<endl;

 }
 int  get_input(float &PMT, float &PV, float &r, int &n)
 {
     int count=0;
    int turns = 10;
    while(turns--)
    {
        cout<<"Enter the Opening Balance(PV): ";
        cin>>PV;
        if(PV!=0.0)
        {
            count++;
        }

        cout<<"Enter the Number of installments You want to pay ";
        cin>>n;
        if(n!=0) 
        {
            count++;
        }

        cout<<"Enter the Fixed installment amount(PMT) : ";
        cin>>PMT;
        if(PMT!=0)
        {
            count++;
        }

        cout<<"Enter the loan interest Rate (without %) : ";
        cin>>r;
        if(r!=0.0)
        {
            count++;
        }


        if(count>=3)
        {
            break;
        }
        else if(count<3){
            
            count = 0;
            cout<<endl<<endl<<endl;
        }
        else if(turns == 1)
        {
            cout<<"Abort you are Entering Wrong input again and again !!! "<<endl;
            return 0;
        }
    }

    complete_four_r(PMT, PV, r, n);
    complete_four_PMT(PMT, PV, r, n);
    complete_four_PV(PMT, PV, r, n);
    complete_four_n(PMT, PV, r, n);

 }

int main() 
{
    float PV=0.0, r=0.0, PMT=0.0;
    int n=0;
    cout<<line()<<"Welcome To Loan EMI calculator";
	cout<<line()<<endl<<endl;
    cout<<"You have to Enter minimum 3 variables to calculate your Loan EMI ";
    cout<<"\n If You don't know the value, Simply hit enter "<<endl<<endl;
    
   int res =  get_input(PMT, PV, r, n);
   if(res == 0)
   {
       exit(0);
   }
   
   int i=0;
   cout<<endl;
   int months = n;
    cout<<"you have to pay loan for "<<n<<" months !!!!"<<endl;         //here months and years are correct dont change anything
   while(ceil(n) >= 0)
   {
      row[i].s_no = i;
      row[i].open_balance = i==1 ? PV : row[i-1].open_balance - row[i-1].principal;
      row[i].principal = PMT - row[i].open_balance*r/(100.0);
      row[i].interest_rate = r;
      row[i].interest = row[i].open_balance*row[i].interest_rate/100.0;
      row[i].installment = PMT;
      row[i].closing_balance = row[i].open_balance-row[i].principal;
      i++; n--;
   }

    cout<<endl<<endl;
    cout<<line()<<"Loan Details with monthly EMI ";
	cout<<line()<<endl<<endl;
    header();
    for(int i=1;i<=months;i++)
    {    
        if(i==months && row[i].closing_balance < 1)
        {
        	row[i].closing_balance=0;
		}
        cout<<setw(4)<<row[i].s_no<<setw(17)
		<<row[i].open_balance<<setw(18)
        <<row[i].principal<<setw(23)
		<<row[i].interest_rate<<setw(18)
		<<row[i].interest<<setw(18)
		<<row[i].installment<<setw(23)
        <<row[i].closing_balance<<endl;
    }





    
}
