#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string ans(n+1,'1');//制作树串,1-树,0-空 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		string t(b-a+1,'0');//制作空串 
		ans.replace(ans.begin()+a,ans.begin()+a+(b-a+1),t);//将树挖掉 
	}
	int tree=0;
	for(int i=0;i<ans.length();i++)//计算剩余树的数目 
		if(ans.at(i)=='1')
			tree++;
	cout<<tree<<endl; 
}
