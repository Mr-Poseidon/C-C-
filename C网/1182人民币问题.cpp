#include<iostream>
using namespace std;

int num,ans=0; 

int main()
{
	cin>>num;//��ֵ 
	int a=num-8;//��֤ÿ����ֵ����һ�� 
	for(int i=0;i<=a/5;i++)//����5Ԫ��ȡ������ 
	{
		int b=a-i*5;
		for(int j=0;j<=b/2;j++)//����2Ԫ��ȡ������(���Ż�) 
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
