#include<iostream>
using namespace std;

int gcd(int a,int b)//最大公约数 
{
	if(b==0)return a;
	else return gcd(b,a%b);
}
int lcm(int a,int b)//最小公倍数 
{
	return a*b/gcd(a,b);
}

int main() 
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<lcm( lcm(a,b),c );
	return 0;
}
