#include<bits/stdc++.h>
#include "header_1.h"
#ifndef three
#define three

using namespace std;

class data_3 {
	public:
		int s_no;
		float open_balance,principal,interest_rate,interest;
		float installment,closing_balance;
}row_3[1000];



bool wrong_input_three(float PMT, float PV, float r, float n)
{
    if(PMT <= 0.0)
    {
        cout<<"PMT Wrong Value !!!"<<endl<<endl;
        return false;
    }
    else if(PV <= 0.0)
    {
        cout<<"PV Wrong Value !!!"<<endl;
        return false;
    }

    else if(r<=0.0)
    {
        cout<<"r Wrong value !!!"<<endl;
        return false;
    }
    else if(n<=0.0)
    {
        cout<<"n Wrong value !!!"<<endl;
        return false;
    }

    else {
        // cout<<"returning true "<<endl;
        return true;
    }
}

          //   PMT/PV = r.(1 + 1/(1+r)^n -1)
 void complete_four_PMT(float &PMT, float &PV, float &r, int &n)
 {     
        
        if(PMT==0.0)
        PMT = (PV*r/100.0)*(1 + 1/(pow(1+r/100.0, n)-1));
        //cout<<"PMT "<<PMT<<endl;
 }

 void complete_four_PV(float &PMT, float &PV, float &r, int &n)
 {    
      if(PV==0.0)
      PV = PMT/((r/100.0)*(1 + 1/(pow(1+r/100.0, n)-1)));
      //cout<<"PV "<<PV<<endl;
 }

void complete_four_r(float &PMT, float &PV, float &r, int &n)
 {      
        float rr = 0;
        if(r==0.0)
        {
        	float temp = PMT/PV*1.0;
            int l = 1;
            int h = 100000;
             float xx = 0.0;
             float bucket =0.0;
             while(l < 10)
             {
                 xx = l/100.0;              //finding rate
                 bucket = xx*(1.0 + ( 1.0/ (pow(xx+1, n) - 1.0) ));

                 if(bucket == temp || abs(bucket-temp)<=0.001){
                     break;
                 }
                 
                // cout<<"l is"<<l<<"  temp is "<<temp<<"bucket = "<<bucket<<endl<<endl;
                 l++;
                 
             }
            // cout<<"l is"<<l<<"  temp is "<<temp<<"bucket = "<<bucket<<endl<<endl;

             r = xx*100;

		}
 }

void complete_four_n(float &PMT, float &PV, float &r, int &n)
 {     
        if(n!=0)
        return ;
        float xx = (PMT/(PV*r/100.0))-1;
        //cout<<"x : "<<xx<<endl;
        float yy = 1.0/xx;
        //cout<<"yy : "<<yy<<endl;
        float zz = yy+1;
        //cout<<"zz : "<<zz<<endl;
        float r1 = (r/100.0)+1;
        //cout<<"r1 : "<<r1<<endl;
        float temp=r1;
        int count = 1;
        while(temp < zz)
        {
             temp=temp*r1;
             count++;
        }

        n = count;
        //cout<<"n "<<n<<endl;

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
          
          

    cout<<"Your Entered Variables are..."<<endl<<endl;
    complete_four_r(PMT, PV, r, n);
    complete_four_PMT(PMT, PV, r, n);
    complete_four_PV(PMT, PV, r, n);
    complete_four_n(PMT, PV, r, n);
    cout<<"PMT : "<<PMT<<endl
        <<"PV : "<<PV<<endl
        <<"R : "<<r<<endl
        <<"Number of installments : "<<n<<endl<<endl;
        if(wrong_input_three(PMT, PV, r, n)==false)
          {
                cout<<"seems wrong set of input values....plizz check that "<<endl<<endl;
                return 0;
          }
          return 1;

 }

void solve_3()
{
  float PV=0.0, r=0.0, PMT=0.0;
    int n=0;
    //cout<<line()<<"Welcome To Loan EMI calculator";
	//cout<<line()<<endl<<endl;
    cout<<"You have to Enter minimum 3 variables to calculate your Loan EMI ";
    cout<<"\n If You don't know the value, Simply write 0 "<<endl<<endl;
    
   int res =  get_input(PMT, PV, r, n);
   if(res == 0)
   {  
       cout<<"Aborting!!!!"<<endl<<endl;
       exit(0);
   }

   //====================================
   //         File handling start
   //====================================

    ofstream fout;
    fout.open("out.csv", ios::app); 
    fout<<endl<<endl;    
    fout<<"PMT : "<<","<<PMT<<endl
    <<"PV : "<<","<<PV<<endl
    <<"R : "<<","<<r<<endl
    <<"Number of installments : "<<","<<n<<endl<<endl;

    //enter header file handling
    fout<<" S.NO"<<","<<"open balance($)"<<","<<"principal($)"
	<<","<<"interest rate(%)"<<","<<"interest($)"
	<<","<<"installment($)"<<","<<"closing balance($)"<<endl;
    //header end



    //====================================
   //         File handling end
   //====================================
   
   int i=0;
   cout<<endl;
   int months = n;
    cout<<"you have to pay loan for "<<n<<" months !!!!"<<endl;         //here months and years are correct dont change anything
   while(ceil(n) >= 0)
   {
      row_3[i].s_no = i;
      row_3[i].open_balance = i==1 ? PV : row_3[i-1].open_balance - row_3[i-1].principal;
      row_3[i].principal = PMT - row_3[i].open_balance*r/(100.0);
      row_3[i].interest_rate = r;
      row_3[i].interest = row_3[i].open_balance*row_3[i].interest_rate/100.0;
      row_3[i].installment = PMT;
      row_3[i].closing_balance = row_3[i].open_balance-row_3[i].principal;
      i++; n--;
   }

    cout<<endl<<endl;
    cout<<line()<<"Loan Details with monthly EMI ";
	cout<<line()<<endl<<endl;
    header1();
    for(int i=1;i<=months;i++)
    {    
        if(i==months && row_3[i].closing_balance < 1)
        {
        	row_3[i].closing_balance=0;
		}
        cout<<setw(4)<<row_3[i].s_no<<setw(17)
		<<row_3[i].open_balance<<setw(18)
        <<row_3[i].principal<<setw(23)
		<<row_3[i].interest_rate<<setw(18)
		<<row_3[i].interest<<setw(18)
		<<row_3[i].installment<<setw(23)
        <<row_3[i].closing_balance<<endl;

        fout<<row_3[i].s_no<<","
		<<row_3[i].open_balance<<","
        <<row_3[i].principal<<","
		<<row_3[i].interest_rate<<","
		<<row_3[i].interest<<","
		<<row_3[i].installment<<","
        <<row_3[i].closing_balance<<endl;
    }

    fout.close();

}


#endif
