#include<bits/stdc++.h>
#include<stdio.h> 
#include<stdlib.h> 
#include<time.h>

//file headers
#include "header_1.h"
#include "header_2.h"
#include "front.h"

//file programs for each type
#include "one.h"
#include "two.h"
#include "three.h"

void clear()
{
    //system("CLS");
    cout<<endl<<endl<<endl;
    line();
    cout<<" WELCOME TO THE LOAN EMI CALCULATOR ";
    line();
    cout<<endl<<endl<<endl;
}

bool do_more()
{   
    cout<<endl<<endl;
    cout<<"Wanna do more....press 1 else 0 : ";
    int x;
    cin>>x;
    if(x==0)
    {
        return false;
    }
    else if(x==1)
    {
        return true;
    }
    else
    {
        {
            cout<<"wrong choice......aborting!!!!"<<endl;
            return false;
        }
    }
    
}

using namespace std;

int main() 
{   
     cout<<endl<<endl<<endl;
     line();
     cout<<" WELCOME TO THE LOAN EMI CALCULATOR ";
     line();
     cout<<endl<<endl<<endl;
     int choice = 1;
     while(choice)
     {
         cout<<"Press 1 to calculate loan EMI for Fixed Principal Payment And Fixed Interest Rate "<<endl;
         cout<<"Press 2 to calculate loan EMI for Fixed Principal Payment And Margin + Parameterised normally distributed interest rate "<<endl;
         cout<<"Press 3 to calculate loan EMI for Fixed Interest Rate and Fixed installment "<<endl;
         cout<<"Press 0 to Exit "<<endl;
         cout<<endl<<endl;
         cout<<"Enter Your Choice : ";
         cin>>choice;
         if(choice == 1)
         {
              solve_1();
              if(do_more())
              {
                  clear();
              }
              else
              {
                  cout<<"Exited Successfully !!!"<<endl;
                  break;
              }
              
              
         }
         else if(choice == 2)
         {
             solve_2();
             if(do_more())
             {
                 clear();
             }
             else
             {
                 cout<<"Exited Successfully!!!"<<endl;
                 break;
             }
             

         }
         else if(choice == 3)
         {
              solve_3();
              if(do_more())
              {
                  clear();
              }
              else
              {
                  cout<<"Exited Successfully!!!"<<endl;
                  break;
              }
              
         }
         else if(choice == 0)
         {
              cout<<"Exited Successfully!!!"<<endl;
              break;
         }
         else
         {
             cout<<"Wrong Choice "<<endl<<endl<<endl;

         }
         
         
     }

}
