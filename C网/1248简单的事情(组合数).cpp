#include<iostream>
using namespace std;

typedef long long int ll;
ll fun(int a,int b)//Çø¼ä³Ë 
{
	ll ans=1;
	for(int i=a;i>b;i--)
		ans*=i;
	return ans;
}
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		cout<<fun(a,a-b)/fun(b,1)<<endl;
	}
	return 0;
}
