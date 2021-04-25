/*
答案记录： 
		1100 4
		123124 6
		12471250 8
		1249668749 10
		124995984373 12
		12499951484374 14
		1249999426562500 16
		124999993505859375 18
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

unsigned long long int n;
unsigned long long int ans=0,num_5=0;
//int wide=2;

int get_wides(unsigned long long int num)//计算位数 
{
	int n=0;
	while(num!=0)
	{
		n++;
		num/=10;
	}
	return n;
}
int count_5(unsigned long long int num)//计算因子5的个数 
{
	int count=0;
	while(num%5==0 && num!=0)
	{
		count++;
		num/=5;
	}
	return count;
}
int main()
{
	cin>>n;
	//n=(unsigned long long int)pow(10,10);
	for(unsigned long long int i=1;i<=n;i++)
	{
		num_5+=count_5(i);
		ans+=num_5;
		/*
		if(i==(unsigned long long int)pow(10,wide))
		{
			cout<<ans<<" "<<get_wides(ans)<<endl;
			wide++;
		}
		*/
	}
	cout<<ans<<endl;
	return 0;
}
