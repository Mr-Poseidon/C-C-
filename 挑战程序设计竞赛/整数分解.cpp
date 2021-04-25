#include<iostream>
#include<map>
#include<cmath>
using namespace std;

map<int,int> prime_factor(int num)//整数分解 
{
	map<int,int> ans;
	for(int i=2;i<=sqrt(num);i++)
	{
		while(num%i==0)
		{
			ans[i]++;
			num/=i;
		}
	}
	if(num!=1)ans[num]++;//最后num为一个素数 
	return ans;
}
int main()
{
	map<int,int> ans;
	ans=prime_factor(14);
	for(map<int,int>::iterator it=ans.begin();it!=ans.end();it++)
	{
		for(int i=0;i < it->second;i++)
			cout<<it->first<<" ";
	}
	return 0;
}
