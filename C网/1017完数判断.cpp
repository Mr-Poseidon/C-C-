//��ȫ��������6��8��β,�����8��β,��ô�Ϳ϶�����28��β.
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
bool is_perfect(long int num)//�ж���ȫ�������������� 
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
