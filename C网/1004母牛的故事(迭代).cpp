//�������μ���棬�޴������ݡ� 
#include<iostream>
#include<cstdio>
using namespace std;

int n;
void fun(int n)
{
	int a[4]={1,0,0,0};//�ĸ����ֱַ�������꣬���꣬���꣬һ��(�ճ���) 
	for(int i=2;i<=n;i++)
	{
		int o_adult=a[0],n_adult=a[1];//o_adult-�Ѿ����꣬n_adult-�������� 
		a[0]+=a[1];
		a[1]=a[2];
		a[2]=a[3];
		a[3]=o_adult+n_adult;
	}
	cout<<a[0]+a[1]+a[2]+a[3]<<endl;
}
int main()
{
	while(~scanf("%d",&n) && n!=0)
		fun(n);
	return 0;
}
