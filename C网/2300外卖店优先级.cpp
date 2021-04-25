#include<iostream>
#include<algorithm> 
#include<cstring>
#define maxn 100005
using namespace std;

typedef long long int ll;


struct Orders{
	ll ts,id;
};

ll n,m,t;
Orders ord[maxn];//���� 
ll f[maxn];//���ȼ� 
ll q[maxn];//���ȼ����� 
ll is_ord[maxn];//ĳʱ���Ƿ��ж��� 


int main()
{
	memset(f,0,sizeof(f));
	memset(q,0,sizeof(q));
	
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++)
		cin>>ord[i].ts>>ord[i].id;
	
	for(int i=1;i<=t;i++)//ʱ��ö�� 
	{
		memset(is_ord,0,sizeof(is_ord));//���� 
		
		for(int j=1;j<=m;j++)//�������� 
			if(ord[j].ts==i)
			{
				f[ord[j].id]+=2;//���ȼ�+2 
				is_ord[ord[j].id]=1;//��� 
			}
			
		for(int j=1;j<=n;j++)//�����̼� 
		{
			if(f[j]>0 && is_ord[j]==0)//���ȼ�>0��û�ж��� 
				f[j]--;
			
			if(f[j]>5)//�������ȼ����� 
				q[j]=1;
			else if(f[j]<=3)//������ȼ�����
				q[j]=0;
		}
	}
	
	int ans=0;
	for(int i=1;i<=n;i++)//���������ȶ����е��̼� 
		if(q[i]==1)
			ans++;
	cout<<ans;	
	return 0;
} 
