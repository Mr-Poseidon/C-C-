#include<iostream>
using namespace std;

//ans[][0]放除数，ans[][1]放余数
unsigned long long int n,ans[2][2]={1,1,0,0};//根据题目假设初值 


void common_min_remainder()//求最小同余数，结果放在ans[0][]中 
{
	while(ans[0][1]!=ans[1][1])
	{
		if(ans[0][1]<ans[1][1])
			ans[0][1]+=ans[0][0];
		else
			ans[1][1]+=ans[1][0];
	}
	ans[0][0]*=ans[1][0];
	return ;
}
int main()
{
	cin>>n; 
	cin>>ans[0][0]>>ans[0][1];//输入第一组数据 

	for(int i=0;i<n-1;i++)
	{
		cin>>ans[1][0]>>ans[1][1];
		common_min_remainder();//求最小同余数 
	}
	cout<<ans[0][1]<<endl;//输出结果 
	return 0;
} 
