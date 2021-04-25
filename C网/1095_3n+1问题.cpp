#include<iostream>
#include<cstdio>
using namespace std;

long int max(long int a,long int b){return a>b?a:b;} 
unsigned long int get_length(unsigned long int num)
{
	unsigned long int ans=0;
	while(num!=1)
	{
		ans++;
		if(num%2==0)
			num/=2;
		else
			num=num*3+1;
	}
	return ans+1;
}
void fun(unsigned long int a,unsigned long int b)
{
	cout<<a<<" "<<b<<" ";
	unsigned long int ans=0;
	if(a>b)
	{
		int t;
		t=a;a=b;b=t;
	}
	for(int i=a;i<=b;i++)
	{
		ans=max(ans,get_length(i));
	}
	cout<<ans<<endl;
}
int main()
{
	unsigned long int a,b;
	while(~scanf("%ld%ld",&a,&b))
		fun(a,b);
	return 0;
}
