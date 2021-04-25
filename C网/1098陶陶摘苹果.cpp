#include<iostream>
#include<cstdio>
using namespace std;

int ans=0,num[10],n; 
int main()
{
	for(int i=0;i<10;i++)
		cin>>num[i];
	cin>>n;
	for(int i=0;i<10;i++)
		if(n+30 >= num[i])
			ans++;
	cout<<ans<<endl;
	return 0;
}
