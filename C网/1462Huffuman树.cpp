#include<iostream>
#include<queue>
using namespace std;

int main()
{
	priority_queue< int,vector<int>,greater<int> > q;//´óµ×¶Ñ 
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		q.push(t);
	}
	
	int ans=0;
	while(q.size()>1)
	{
		int a,b;
		a=q.top();
		q.pop();
		b=q.top();
		q.pop();
		ans+=a+b;
		q.push(a+b);
	}
	cout<<ans;
	return 0;	
} 
