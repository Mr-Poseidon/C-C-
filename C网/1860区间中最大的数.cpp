#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int num[1005];
int n,q;

int main()
{
	num[0]=-1;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	cin>>q;
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		vector<int> t(num+a,num+b+1);
		sort(t.begin(),t.end());
		cout<<t.back()<<endl; 
	}
	return 0;
} 
