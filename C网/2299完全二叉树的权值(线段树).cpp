#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int n,deep,ans=0; 
int a[1000000];

int main()
{
	cin>>n;
	for(int i=0;i<=2*n;i++)//初始化 
		a[i]=0;
	for(int i=1;i<=n;i++)//输入 
		cin>>a[i];
		
	for(int i=0;n>0;i++)//树的深度，树根为0 
	{
		int sum=0;
		// 深度起点 pow(2,i) 深度终点 pow(2,i+1)-1 
		for(int j=pow(2,i);j<pow(2,i+1);j++)
			sum+=a[j];//深度权值累加 
		if(sum>ans)
		{
			ans=sum;
			deep=i+1;//根的深度为1，所以+1
		}
		n-=pow(2,i);
	}
	cout<<deep;
	return 0; 
}

