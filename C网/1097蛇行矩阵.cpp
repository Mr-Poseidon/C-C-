#include<iostream>
#include<cstdio>
using namespace std;

int n,num=1;
int map[100][100];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)//构造数组 
	{
		int k=0;
		for(int j=i;j>=0;j--)
		{
			map[j][k]=num++;
			k++;
		}
	}
	for(int i=0;i<n;i++)//输出数组 
	{
		for(int j=0;j<n-i;j++)
		{
			if(j)//输出间隔,末尾不要 
				cout<<" ";
			cout<<map[i][j];
		}
		cout<<endl;
	}
	return 0;
}
