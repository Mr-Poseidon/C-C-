#include<iostream>
#include<cstdio>
using namespace std;

double m,n;

double fun(double m,int n,int k)
{
	if(k==n)
	{
		printf("%.2lf ",m/2);
		return m;//��n��ֻ���㷴���߶ȣ������� 
	}
	return m+m/2+fun(m/2,n,k+1);
}
int main()
{

	cin>>m>>n;
	printf("%.2lf",fun(m,n,1));
	return 0;
} 
