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
	for(int i=0;i<=2*n;i++)//��ʼ�� 
		a[i]=0;
	for(int i=1;i<=n;i++)//���� 
		cin>>a[i];
		
	for(int i=0;n>0;i++)//������ȣ�����Ϊ0 
	{
		int sum=0;
		// ������ pow(2,i) ����յ� pow(2,i+1)-1 
		for(int j=pow(2,i);j<pow(2,i+1);j++)
			sum+=a[j];//���Ȩֵ�ۼ� 
		if(sum>ans)
		{
			ans=sum;
			deep=i+1;//�������Ϊ1������+1
		}
		n-=pow(2,i);
	}
	cout<<deep;
	return 0; 
}

