#include<iostream>
using namespace std;

int gcd(int a,int b)//���Լ�� 
{
	if(b==0)return a;
	else return gcd(b,a%b);
}
int lcm(int a,int b)//��С������ 
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
