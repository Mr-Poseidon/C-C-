#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	int n;
	double ans=0,v;
	int count;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%*s %lf %d",&v,&count);//ȥ��������ֻ�����ܻ��� 
		ans+=v*count;
	}
	printf("%0.6lf",ans);
	return 0;
}
 
