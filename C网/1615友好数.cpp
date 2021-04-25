#include<iostream>
#include<cmath>
using namespace std;

int div_sum(int num)
{
	int ans=0;
	for(int i=1;i<=sqrt(num);i++)
		if(num%i==0)
		{
			ans+=i;
			if(i!=num/i)
				ans+=num/i;
		}
	return ans-num;//¿Ûµô±¾Éí 
}
int main()
{
	int a,b;
	cin>>a>>b;
	if(div_sum(a)==b && a==div_sum(b))
		cout<<"yes";
	else 
		cout<<"no";
	return 0;
} 
