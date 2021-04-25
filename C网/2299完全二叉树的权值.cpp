#include<iostream>
#include<algorithm>
#include<cmath> 
using namespace std;

int n;

int main()
{
	int m=1,s=0,d=0,ans;//m-该层元素数，s-总和，d-深度，ans-答案 
	cin>>n;
	
	while(n>0)
	{
		d++;
		int sum=0;
		
		// min(n,m)-该层实际个数 
		for(int i=0;i<min(n,m);i++)//该层总和 
		{
			int t;
			cin>>t;
			sum+=t;
		}
		
		if(sum>s)//判断 
		{
			s=sum;
			ans=d;
		}
		
		n-=m;//计算剩余元素 
		m*=2;//下层元素个数 
	}
	cout<<ans;
	return 0;
} 
