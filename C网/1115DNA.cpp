#include<iostream>
using namespace std;

char s[40][40];

//ע�⣺�������ĸΪ��дX 
void fun()
{
	int a,b;
	cin>>a>>b; 
	for(int i=0;i<a;i++)//��ʼ���ַ����� 
		for(int j=0;j<a;j++)
			s[i][j]=' ';
	
	for(int i=0;i<a;i++)
	{
		s[i][i]='X';//���Խ��� 
		s[i][a-1-i]='X';//б�Խ��� 
	}
	
	 for(int i=0;i<a;i++)//��ӡһ��������DNA 
	 {
	 	if(i)cout<<endl;
	 	for(int j=0;j<a;j++)
			cout<<s[i][j];	
	 }
	 
	 b-=1;
	 while(b--)//��ӡ�ظ����� 
	 {
		cout<<endl;
	 	for(int i=1;i<a;i++)
		 {
		 	if(i>1)cout<<endl;
		 	for(int j=0;j<a;j++)
				cout<<s[i][j];
		 }
	 }
	 return;	
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		if(i)cout<<endl<<endl;
		fun();
	}
	return 0;
}
