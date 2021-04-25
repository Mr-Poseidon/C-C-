#include<iostream>
#include<cmath>
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
	for(int i=2;i<num;i++)
		if(is_prime(i))
			cout<<i<<endl;
	return 0;
}
