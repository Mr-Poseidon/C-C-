#include<iostream>
#include<cstdio>
using namespace std;

int n,num=1;
int map[100][100];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)//�������� 
	{
		int k=0;
		for(int j=i;j>=0;j--)
		{
			map[j][k]=num++;
			k++;
		}
	}
	for(int i=0;i<n;i++)//������� 
	{
		for(int j=0;j<n-i;j++)
		{
			if(j)//������,ĩβ��Ҫ 
				cout<<" ";
			cout<<map[i][j];
		}
		cout<<endl;
	}
	return 0;
}
