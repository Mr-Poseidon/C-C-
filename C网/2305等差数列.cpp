#include<iostream>
#include<algorithm>
using namespace std;

int n,a[100005],d,mod;

int main()//���� 
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	
	if(a[0]==a[n-1])//d=0
	{
		cout<<n;
		return 0;
	}
	
	for(int i=109;i>0;i--)//����ö�����й���d 
	{
		bool f=true;
		mod=a[0]%i;
		for(int j=0;j<n;j++)//�Ȳ�����ͬģ������� 
			if(a[j]%i!=mod)
			{
				f=false;
				break;
			}

		if(f)
		{
			d=i;
			break;
		}
	}
	cout<<(a[n-1]-a[0])/d+1;
	return 0;
}
