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
		
		ss=string(3-(ss.size()%3),'0')+ss;//���� 
		
		for(int i=0;i<ss.size();i+=3)//3λ16����==4λ8���� 
		{
			int t;
			char st[4];
			sscanf(&(ss.c_str()[i]),"%3X",&t);
			sprintf(st,"%04o",t);//ע��������� 
			ans+=string(st);
		}
		
		while(ans[0]=='0')//ȥ��ǰ��0 
			ans.erase(0,1);
		
		cout<<ans<<endl;
	}
	return 0;
}
