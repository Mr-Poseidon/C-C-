#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;

unsigned int num;

bool is_prime(unsigned int num)
{
	for(int i=2;i<=sqrt(num);i++)
		if(num%i==0)return false;
	return true;
}
int main()
{
	cin>>num;
	if(is_prime(num))
		cout<<"Y"<<endl;
	else
		cout<<"N"<<endl;
	return 0;
}
