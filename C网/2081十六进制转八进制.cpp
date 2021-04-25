#include<iostream>
#include<cstdio>
using namespace std;

int n;

int main()
{
	cin>>n;
	while(n--)
	{
		string ss,ans;
		
		cin>>ss;
		
		ss=string(3-(ss.size()%3),'0')+ss;//补零 
		
		for(int i=0;i<ss.size();i+=3)//3位16进制==4位8进制 
		{
			int t;
			char st[4];
			sscanf(&(ss.c_str()[i]),"%3X",&t);
			sprintf(st,"%04o",t);//注意输出补零 
			ans+=string(st);
		}
		
		while(ans[0]=='0')//去掉前导0 
			ans.erase(0,1);
		
		cout<<ans<<endl;
	}
	return 0;
}
