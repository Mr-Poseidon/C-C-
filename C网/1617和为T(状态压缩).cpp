#include<iostream>
using namespace std;

int num[24]={0};
int n,T,ans=0;

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>num[i];
	cin>>T;
	
	for(int i=1;i<(1<<n);i++)//状态压缩暴力搜索 
	{
		int t,j,sum=0;//t-临时变量，j-数组指针，sum-集合元素和 
		
		t=i,j=0;
		while(t)//计算集合元素 
		{
			if(t&1)sum+=num[j];//选择该元素 
			j++;//数组指针右移 
			t>>=1;//状态右移1位 
		}
		
		if(sum==T)//符合条件，输出 
		{
			ans++;
			
			t=i,j=0;
			while(t)
			{
				if(t&1)cout<<num[j]<<' ';
				j++;
				t>>=1; 
			}
			cout<<endl;
		}
	}
	cout<<ans;
	return 0;
} 
