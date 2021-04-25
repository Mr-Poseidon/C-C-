#include<iostream>
#include<cstring>
using namespace std;

// a-存数组，m-存访问次数
int n,a[100005],m[2000005];

int main()//O(n) 
{
	memset(a,0,sizeof(a));
	memset(m,0,sizeof(m));
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	for(int i=0;i<n;i++)
	{
		while(1)
		{
			if(m[a[i]]==0)
			{
				m[a[i]]++; 
				break;
			}
			else
			{
				m[a[i]]++;
				a[i]+=m[a[i]]-1;//该数加上该数的访问次数-1可能未访问过 
			}			
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i)cout<<" ";
		cout<<a[i];
	}
	return 0;
	
}
