#include<iostream>
#include<cstring>
using namespace std;

int dir[5005];//F-0,B-1 
int f[5005];//��ת��Ϊ1������Ϊ0 
int n,k,times=0;

int calc(int k)
{
	memset(f,0,sizeof(f));
	int ans=0;//�ܷ�ת���� 
	int sum=0;//k����ķ�ת���� 
	
	for(int i=0;i+k-1<n;i++)
	{
		if((dir[i]+sum)%2!=0)//��ת 
		{
			f[i]=1;
			ans++;
		}
		
		sum+=f[i];
		
		if(i-k+1>=0)
			sum-=f[i-k+1];
	}
	
	for(int i=n-k+1;i<n;i++)
	{
		if((dir[i]+sum)%2!=0)//�޽� 
			return -1;
		if(i-k+1>=0)//����Խ��
			sum-=f[i-k+1]; 
	}
	return ans; 
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		char ch;
		cin>>ch;
		if(ch=='F')dir[i]=0;
		else if(ch=='B') dir[i]=1;
	}
	
	k=1,times=n;
	for(int i=1;i<=n;i++)
	{
		int t=calc(i);
		if(t>=0 && t<times)
		{
			times=t;
			k=i;
		}
	}
	cout<<k<<" "<<times;
	return 0;
} 
