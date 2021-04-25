#include<iostream>
#include<algorithm> 
using namespace std;

bool m[10005];
int n;

int next(int num)
{
	int ans=num;
	while(num)
	{
		ans+=(num%10);
		num/=10;
	}
	return ans;
}
bool fun(int num)
{
	if(num>=n)return true;
	else return m[num]=fun(next(num));
}
int main()
{
	cin>>n;
	fill(m,m+n,false);
	for(int i=1;i<n;i++)
	{
		if(m[i]==false)//没有生成元 
			fun(next(i));
	}
	
	for(int i=1;i<n;i++)
		if(m[i]==false)//没有生成元
			cout<<i<<endl;
	return 0;
}
