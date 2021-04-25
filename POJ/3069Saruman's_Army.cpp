#include<iostream>
#include<algorithm>
using namespace std;

int n,r,a[1005];

int main()
{
	while(cin>>r>>n && n!=-1 && r!=-1)
	{
		for(int i=0;i<n;i++)
			cin>>a[i];
		
		sort(a,a+n);	
		
		int i=0,ans=0;
		while(i<n)
		{
			int l=a[i++];//左边界点 
			while(i<n && a[i]<=l+r)i++;
			
			int p=a[i-1];//标记点 
			while(i<n && a[i]<=p+r)i++;
			
			ans++; 
		}
		cout<<ans<<endl;
	}
	return 0;
}


