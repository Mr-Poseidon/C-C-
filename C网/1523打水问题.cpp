#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long int ll;
ll n,m,ans=0;
int a[1005];

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	
	for(int i=0;i<m;i++)//����ˮ��ͷ 
	{
		ll s=0;
		for(int j=i+m;j<n;j+=m)//������ˮ��ͷ���� 
		{
			a[j]+=a[j-m];//�����һ���˵ĵȴ�ʱ��
			s+=a[j-m]; 
		}
		ans+=s;
	}
	cout<<ans;
	return 0;
} 
