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
	for(int i=1;i<=n;i++)//行 
		pri(a,i);
	cout<<endl;
	for(int i=1;i<=n;i++)//列 
		pri(i,b);
	cout<<endl;
	int t=min(a,b);
	for(int i=a-t+1,j=b-t+1 ; i<=n && j<=n ; i++,j++)//左上-右下 
		pri(i,j);
	cout<<endl;
	t=min(a,n-b);
	for(int i=b+t,j=a-t ; i>=0 && j<=n ; i--,j++)//左下-右上 
		pri(i,j);
	return 0; 
} 
