#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string ans(n+1,'1');//��������,1-��,0-�� 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		string t(b-a+1,'0');//�����մ� 
		ans.replace(ans.begin()+a,ans.begin()+a+(b-a+1),t);//�����ڵ� 
	}
	int tree=0;
	for(int i=0;i<ans.length();i++)//����ʣ��������Ŀ 
		if(ans.at(i)=='1')
			tree++;
	cout<<tree<<endl; 
}
