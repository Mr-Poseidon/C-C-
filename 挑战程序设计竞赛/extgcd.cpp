// https://www.cnblogs.com/zyf0163/p/4792953.html      �����ο����� 
#include<iostream>
using namespace std;

int gcd(int a,int b)//շת����� 
{
	if(b==0)return a;
	return gcd(b,a%b);
}
int extgcd(int a,int b,int& x,int &y)
{
	int d=a;
	if(b!=0)
	{
		d=extgcd(b,a%b,y,x);
		/*
		��������extgcd��x yλ�û��������� �� 
		{
			x1=y2 
			y1=x2 ******һʽ 
		}
		��ŷ����ö����Ƴ���
		{
			x1=y2  
			y1=x2-(a/b)*y2 ******��ʽ
		}
		��һʽ�����ʽ�ã�
		{
			x1=x1
			y1=y1-(a/b)*x1  �� x����,y-=(a/b)*x 
		}
		*/
		y-=(a/b)*x;
	}
	else
	{
		x=1;
		y=0;
	}
	return d;//d=gcd(a,b)
}
int main()
{

	int a,b,x,y;
	extgcd(11,2,x,y);// 1 -5 
	cout<<x<<" "<<y<<endl;

	return 0;
} 
