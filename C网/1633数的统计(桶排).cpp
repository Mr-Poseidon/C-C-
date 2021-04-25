#include<iostream>
#include<map>
using namespace std;

map<int,int> p;
int n;

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		p[t]++;
	}
	
	for(map<int,int>::iterator it=p.begin();it!=p.end();it++)
		cout<<it->first<<' '<<it->second<<endl;
	return 0;
} 
