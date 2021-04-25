#include<iostream>
#include<algorithm>
using namespace std;

int m,n,k;
char a[11];

int fun(int num)
{
	int ans=1;
	for(int i=1;i<=num;i++)
		ans*=i;
	return ans;
}
int main()
{
	cin>>m>>n>>k;
	for(int i=0;i<n;i++)
		a[i]='1';
	for(int i=n;i<n+k;i++)
		a[i]='2';
	
	int ans=0;
	do
	{
		int t=0;
		bool f=true;
		for(int i=0;i<m;i++)
		{
			if(a[i]=='1')t++;
			if(a[i]=='2')t--;
			if(t<0)f=false;
		}
		if(f)ans++;
	}while(next_permutation(a,a+m));
	
	cout<<ans*fun(n)*fun(k);
	return 0;
}
