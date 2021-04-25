#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,m;
vector<long long int> num;

bool fun()
{
	num.clear();
	cin>>m;
	while(m--)
	{
		int t;
		cin>>t;
		num.push_back(t);
	}
	sort(num.begin(),num.end());
	
	int d=num[1]-num[0];//¹«²î
	 
	for(int i=1;i<num.size();i++)//ÅÐ¶ÏµÈ²î 
		if(num[i]-num[i-1]!=d)
			return false;
	
	return true;
}
int main()
{
	cin>>n;
	while(n--)
	{
		if(fun())cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}
 
