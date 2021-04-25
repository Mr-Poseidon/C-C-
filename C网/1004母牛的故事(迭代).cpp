//迭代依次计算版，无储存数据。 
#include<iostream>
#include<cstdio>
using namespace std;

int n;
void fun(int n)
{
	int a[4]={1,0,0,0};//四个部分分别代表：成年，三岁，两岁，一岁(刚出生) 
	for(int i=2;i<=n;i++)
	{
		int o_adult=a[0],n_adult=a[1];//o_adult-已经成年，n_adult-即将成年 
		a[0]+=a[1];
		a[1]=a[2];
		a[2]=a[3];
		a[3]=o_adult+n_adult;
	}
	cout<<a[0]+a[1]+a[2]+a[3]<<endl;
}
int main()
{
	while(~scanf("%d",&n) && n!=0)
		fun(n);
	return 0;
}
