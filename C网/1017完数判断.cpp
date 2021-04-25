//完全数都是以6或8结尾,如果以8结尾,那么就肯定是以28结尾.
#include<iostream>
using namespace std;

int factor[100],x=0;

void pri(long int num)
{
	cout<<num<<" its factors are";
	for(int i=0;i<x;i++)
			cout<<" "<<factor[i];
	cout<<endl;
}
bool is_perfect(long int num)//判断完全数，并储存因子 
{
	long int sum=0;
	long int half=num/2;
	for(int i=1;i<=half;i++)
		if(num%i==0)
		{
			factor[x]=i;
			x++;
			sum+=i;
		}		
	if(sum==num)return true;
	else return false;
}
int main()
{
	long int num;
	cin>>num;
	for(int i=2;i<num;i++)
	{
		if(i%10==6 || i%100==28)
			if(is_perfect(i))
				pri(i);	
		x=0;	
	}
	return 0;
}
