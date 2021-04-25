#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

/*
平面向量夹角公式：cos=(ab的内积)/(|a||b|)

（1）上部分：a与b的数量积坐标运算:设a=(x1,y1),b=(x2,y2),则a·b=x1x2+y1y2

（2）下部分：是a与b的模的乘积：设a=(x1,y1),b=(x2,y2)，则(|a||b|）=根号下（x1平方+y1平方）*根号下（x2平方+y2平方）

正切公式用tan表示，余角公式用cos表示。正切公式（直线的斜率公式）:k=(y2-y1)/(x2-x1)，余弦公式（直线的斜率公式）:k=(y2-y1)/(x2-x1)。
*/
int main()
{
	int n,a,b,c,d;
	cin>>n;
	while(n--)
	{
		cin>>a>>b>>c>>d;
		double s1=(a*c)+(b*d);
		double s2=sqrt((a*a)+(b*b))*sqrt((c*c)+(d*d));
		double s3=s1/s2;
		printf("%.2lf\n",acos(s3)*180/3.1415926);
	}
	return 0;
} 
