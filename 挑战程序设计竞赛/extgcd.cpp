// https://www.cnblogs.com/zyf0163/p/4792953.html      ——参考博客 
#include<iostream>
using namespace std;

int gcd(int a,int b)//辗转相除法 
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
		由于上面extgcd中x y位置互换，所以 ： 
		{
			x1=y2 
			y1=x2 ******一式 
		}
		由欧几里得定理推出：
		{
			x1=y2  
			y1=x2-(a/b)*y2 ******二式
		}
		由一式代入二式得：
		{
			x1=x1
			y1=y1-(a/b)*x1  即 x不变,y-=(a/b)*x 
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
