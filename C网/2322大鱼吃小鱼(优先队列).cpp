#include<iostream>
#include<queue>
using namespace std;

int n,m;

int main()
{
	priority_queue< int,vector<int>,greater<int> > q;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		q.push(t);
	}
	for(int i=0;i<m;i++)
	{
		int t=0;
		t+=q.top();q.pop();
		t+=q.top();q.pop();
		q.push(t);
	}
	cout<<q.top();
	return 0;
		
}
