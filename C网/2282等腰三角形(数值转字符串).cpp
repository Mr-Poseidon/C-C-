#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
using namespace std;

int n,num=0;
char map[605][605];
string s;

void fun(int n)//��ȡ���������ַ��� 
{
	int num=0;
	while(s.size()<=n)
	{
		num++;
		char ch[10];
		sprintf(ch,"%d",num);//��ֵת�ַ��� 
		s+=string(ch);
	}
}

int main()
{
	cin>>n;
	fun(2*n+(n-2)*2);//2*n+(n-2)*2Ϊ������ַ����� 
//	cout<<s<<endl;
	
	for(int i=1;i<=2*n;i++)//��ʼ�� 
		for(int j=1;j<=2*n;j++)
			map[i][j]='.';
	
	int p=0;
	for(int i=1,j=n;i<n;i++,j--)//��б����� 
		map[i][j]=s[p++];
	
	for(int i=1;i<n*2;i++)//�±���� 
		map[n][i]=s[p++];
	
	for(int i=n-1,j=2*n-2;i>1;i--,j--)//��б����� 
		map[i][j]=s[p++];
	
	
	for(int i=1;i<=n;i++)//��� 
	{
		for(int j=1;j<n+i;j++)
			cout<<map[i][j];
		if(i<n)
			cout<<endl;
	}
		
	return 0;
}
