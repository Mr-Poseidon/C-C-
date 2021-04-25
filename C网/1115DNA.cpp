#include<iostream>
using namespace std;

char s[40][40];

//注意：输出的字母为大写X 
void fun()
{
	int a,b;
	cin>>a>>b; 
	for(int i=0;i<a;i++)//初始化字符数组 
		for(int j=0;j<a;j++)
			s[i][j]=' ';
	
	for(int i=0;i<a;i++)
	{
		s[i][i]='X';//正对角线 
		s[i][a-1-i]='X';//斜对角线 
	}
	
	 for(int i=0;i<a;i++)//打印一个完整的DNA 
	 {
	 	if(i)cout<<endl;
	 	for(int j=0;j<a;j++)
			cout<<s[i][j];	
	 }
	 
	 b-=1;
	 while(b--)//打印重复部分 
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
