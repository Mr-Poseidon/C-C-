#include<iostream>
#include<algorithm>
#include<cmath> 
using namespace std;

int n;

int main()
{
	int m=1,s=0,d=0,ans;//m-�ò�Ԫ������s-�ܺͣ�d-��ȣ�ans-�� 
	cin>>n;
	
	while(n>0)
	{
		d++;
		int sum=0;
		
		// min(n,m)-�ò�ʵ�ʸ��� 
		for(int i=0;i<min(n,m);i++)//�ò��ܺ� 
		{
			int t;
			cin>>t;
			sum+=t;
		}
		
		if(sum>s)//�ж� 
		{
			s=sum;
			ans=d;
		}
		
		n-=m;//����ʣ��Ԫ�� 
		m*=2;//�²�Ԫ�ظ��� 
	}
	cout<<ans;
	return 0;
} 
