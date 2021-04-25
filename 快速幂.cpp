#include<iostream>
using namespace std;

int pow_mod(int num,int n)//快速幂 
{
	int ans=1;
	while(n)//幂右移后左边补零，当幂为零时结束计算 
	{
		if(n&1)
			ans*=num;
		num*=num;//数自乘 
		n>>=1;//幂右移一位 
	}
	return ans;
}

int main()
{
	for(int i=0;i<11;i++)
	cout<<pow_mod(2,i)<<endl;
	return 0;
} 
