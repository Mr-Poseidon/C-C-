#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> a;

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int m;
		cin>>m;
		for(int i=0;i<m;i++)
		{
			int t;
			cin>>t;
			a.push_back(t);
		}
		sort(a.begin(),a.end(),less<int>());
		cout<<a.at(1)<<endl;;		
	}
	return 0;
	
} 
