#include<bits/stdc++.h>
#ifndef header_1
#define header_1

using namespace std;

void header1()
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

#endif