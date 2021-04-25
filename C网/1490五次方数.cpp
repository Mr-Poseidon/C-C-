#include<iostream>
#include<cmath>
using namespace std;

int is_ans(int num)
{
	int ans=0;
	while(num)
	{
		ans+=pow(num%10,5);
		num/=10;
	}
	return ans;
}
int main()
{
	for(int i=10;i<=194979;i++)
	{
		if(i==is_ans(i))
			cout<<i<<endl;
	}
	return 0;
}
 
