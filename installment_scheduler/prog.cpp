#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>p1, pair<int,int>p2){
    if(p1.second>p2.second)
	{
        return true;
    }
    else if(p1.second==p2.second)
	{
        if(p1.first<p2.first)
		{
            return true;
        }
        else
		{
            return false;
        }
    }
    else return false;
}

int main() {
    //cout<<"Hello World!";
    int arr[1000];
    int n;
    cin>>n;
    map<int,int>m;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        m[x]++;
    }

    vector<pair<int,int>>v;
    for(auto i=m.begin();i !=m.end();i++)
    {
        int x=i->first;
        int y=i->second;
        pair<int,int>p;
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(),v.end(),cmp);
    
    for(auto i=v.begin();i!=v.end();i++)
    {
    	int num=i->first;
    	int freq = i->second;
    	for(int j=0; j<freq;j++){
    		cout<<num<<" ";
		}
	}
}

bool cmp2(int x,int y){
	if(x<y){
		cout<<x<<" "<<y<<endl;
		return false;      //it means no swapping
	}
	else 
	return true; //it means swapping
}

//false means no swapping
//true it means swapping
/*
int main()
{
	int n;
	cin>>n;
	int arr[100];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n,cmp2);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
}
*/
