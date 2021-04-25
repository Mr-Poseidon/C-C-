//两数的乘积除以最大公因数就是最小公倍数 
#include<iostream>
using namespace std;

int main()
{
	unsigned int m,n,factor;
	cin>>m>>n;
	int min = m>n?n:m;
	for(int i=min;i>0;i--)
		if(m%i==0 && n%i==0)
		{
			factor=i;
			break;
		}
	cout<<factor<<" "<<n*m/factor<<endl;
	return 0;
}
