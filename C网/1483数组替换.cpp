#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> vec;

vec fun(vec a,int n,vec b,int m)
{
	vec ans;
	for(int i=0;i<n;i++)//a的前n个数 
		ans.push_back(a[i]);
	for(int i=0;i<m;i++)//b的前m个数 
		ans.push_back(b[i]);
	for(int i=n+m;i<a.size();i++)//当a数组大于n+m时，补全尾部 
		ans.push_back(a.at(i));
	return ans;
}
int main()
{
	int n,m;
	vec a,b;

	cin>>n>>m;
	
	for(int i=0;i<n;i++)//输入a 
	{
		int t;
		cin>>t;
		a.push_back(t);
	}
	for(int i=0;i<m;i++)//输入b
	{
		int t;
		cin>>t;
		b.push_back(t);
	}
	
	cin>>n>>m;

	vec ans=fun(a,n,b,m);

	for(int i=0;i<ans.size();i++)
	{
		if(i)cout<<',';
		cout<<ans[i];
	}
	return 0;
} 
