#include<iostream>
using namespace std;

int num[24]={0};
int n,T,ans=0;

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>num[i];
	cin>>T;
	
	for(int i=1;i<(1<<n);i++)//״̬ѹ���������� 
	{
		int t,j,sum=0;//t-��ʱ������j-����ָ�룬sum-����Ԫ�غ� 
		
		t=i,j=0;
		while(t)//���㼯��Ԫ�� 
		{
			if(t&1)sum+=num[j];//ѡ���Ԫ�� 
			j++;//����ָ������ 
			t>>=1;//״̬����1λ 
		}
		
		if(sum==T)//������������� 
		{
			ans++;
			
			t=i,j=0;
			while(t)
			{
				if(t&1)cout<<num[j]<<' ';
				j++;
				t>>=1; 
			}
			cout<<endl;
		}
	}
	cout<<ans;
	return 0;
} 
