#include<iostream>
using namespace std;

char ans[3][12];
int a,b,c,d;

void fun(int site,int num)
{
	site=site*3-3;
	if(num==0)
	{
		ans[0][site]=' ';ans[0][site+1]='_';ans[0][site+2]=' ';
		ans[1][site]='|';ans[1][site+1]=' ';ans[1][site+2]='|';
		ans[2][site]='|';ans[2][site+1]='_';ans[2][site+2]='|';
	}
	if(num==1)
	{
		ans[0][site]=' ';ans[0][site+1]=' ';ans[0][site+2]=' ';
		ans[1][site]=' ';ans[1][site+1]=' ';ans[1][site+2]='|';
		ans[2][site]=' ';ans[2][site+1]=' ';ans[2][site+2]='|';
	}
	if(num==2)
	{
		ans[0][site]=' ';ans[0][site+1]='_';ans[0][site+2]=' ';
		ans[1][site]=' ';ans[1][site+1]='_';ans[1][site+2]='|';
		ans[2][site]='|';ans[2][site+1]='_';ans[2][site+2]=' ';
	}
	if(num==3)
	{
		ans[0][site]=' ';ans[0][site+1]='_';ans[0][site+2]=' ';
		ans[1][site]=' ';ans[1][site+1]='_';ans[1][site+2]='|';
		ans[2][site]=' ';ans[2][site+1]='_';ans[2][site+2]='|';
	}
	if(num==4)
	{
		ans[0][site]=' ';ans[0][site+1]=' ';ans[0][site+2]=' ';
		ans[1][site]='|';ans[1][site+1]='_';ans[1][site+2]='|';
		ans[2][site]=' ';ans[2][site+1]=' ';ans[2][site+2]='|';
	}
	if(num==5)
	{
		ans[0][site]=' ';ans[0][site+1]='_';ans[0][site+2]=' ';
		ans[1][site]='|';ans[1][site+1]='_';ans[1][site+2]=' ';
		ans[2][site]=' ';ans[2][site+1]='_';ans[2][site+2]='|';
	}
	if(num==6)
	{
		ans[0][site]=' ';ans[0][site+1]='_';ans[0][site+2]=' ';
		ans[1][site]='|';ans[1][site+1]='_';ans[1][site+2]=' ';
		ans[2][site]='|';ans[2][site+1]='_';ans[2][site+2]='|';
	}
	if(num==7)
	{
		ans[0][site]=' ';ans[0][site+1]='_';ans[0][site+2]=' ';
		ans[1][site]=' ';ans[1][site+1]=' ';ans[1][site+2]='|';
		ans[2][site]=' ';ans[2][site+1]=' ';ans[2][site+2]='|';
	}
	if(num==8)
	{
		ans[0][site]=' ';ans[0][site+1]='_';ans[0][site+2]=' ';
		ans[1][site]='|';ans[1][site+1]='_';ans[1][site+2]='|';
		ans[2][site]='|';ans[2][site+1]='_';ans[2][site+2]='|';
	}
	if(num==9)
	{
		ans[0][site]=' ';ans[0][site+1]='_';ans[0][site+2]=' ';
		ans[1][site]='|';ans[1][site+1]='_';ans[1][site+2]='|';
		ans[2][site]=' ';ans[2][site+1]='_';ans[2][site+2]='|';
	}
}
int main()
{
	while(cin>>a>>b>>c>>d)
	{
		fun(1,a);
		fun(2,b);
		fun(3,c);
		fun(4,d);
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<12;j++)
				cout<<ans[i][j];
			cout<<endl;
		}	
	}
	return 0;	
} 
