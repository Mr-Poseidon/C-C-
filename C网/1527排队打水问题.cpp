#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int a[505];

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(i>=m)a[i]+=a[i-m];//����ʱ��=�ȴ�ʱ��+��ˮʱ�� 
		ans+=a[i];
	}
	cout<<ans;
	return 0;
} 
