#include<iostream>
using namespace std;

int pow_mod(int num,int n)//������ 
{
	int ans=1;
	while(n)//�����ƺ���߲��㣬����Ϊ��ʱ�������� 
	{
		if(n&1)
			ans*=num;
		num*=num;//���Գ� 
		n>>=1;//������һλ 
	}
	return ans;
}

int main()
{
	for(int i=0;i<11;i++)
	cout<<pow_mod(2,i)<<endl;
	return 0;
} 
