#include<iostream>
#include<algorithm>
using namespace std;

int len,n,t;

int main()
{
	int cases;
	cin>>cases;
	while(cases--)
	{
		cin>>len>>n;
		int amax=0,amin=0;
		for(int i=0;i<n;i++)
		{
			cin>>t;//t-��������
			// t,len-t �������Ͼ��������˵��ֵ 
			amin=max(amin,min(t,len-t));
			amax=max(amax,max(t,len-t));
		}
		cout<<amin<<" "<<amax<<endl;
	}
	return 0;
}
