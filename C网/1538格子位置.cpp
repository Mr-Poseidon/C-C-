#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a,b;

void pri(int i,int j)
{
	printf("(%d,%d)",i,j);
}

int main()
{
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)//�� 
		pri(a,i);
	cout<<endl;
	for(int i=1;i<=n;i++)//�� 
		pri(i,b);
	cout<<endl;
	int t=min(a,b);
	for(int i=a-t+1,j=b-t+1 ; i<=n && j<=n ; i++,j++)//����-���� 
		pri(i,j);
	cout<<endl;
	t=min(a,n-b);
	for(int i=b+t,j=a-t ; i>=0 && j<=n ; i--,j++)//����-���� 
		pri(i,j);
	return 0; 
} 
