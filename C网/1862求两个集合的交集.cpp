#include<iostream>
#include<set>
#include<algorithm> 
using namespace std;

int n,m;

int main()
{
	set<int> a,b,c;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		a.insert(t);
	}
	for(int i=0;i<m;i++)
	{
		int t;
		cin>>t;
		b.insert(t);
	}
	
	set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.end()));
	//sort(c.begin(),c.end());
	int t=0;
	for(set<int>::iterator it=c.begin();it!=c.end();it++)
	{	
		if(t++)cout<<" ";
		cout<<*it;
	}
	return 0;
}
 
