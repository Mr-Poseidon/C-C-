#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

/*
ƽ�������нǹ�ʽ��cos=(ab���ڻ�)/(|a||b|)

��1���ϲ��֣�a��b����������������:��a=(x1,y1),b=(x2,y2),��a��b=x1x2+y1y2

��2���²��֣���a��b��ģ�ĳ˻�����a=(x1,y1),b=(x2,y2)����(|a||b|��=�����£�x1ƽ��+y1ƽ����*�����£�x2ƽ��+y2ƽ����

���й�ʽ��tan��ʾ����ǹ�ʽ��cos��ʾ�����й�ʽ��ֱ�ߵ�б�ʹ�ʽ��:k=(y2-y1)/(x2-x1)�����ҹ�ʽ��ֱ�ߵ�б�ʹ�ʽ��:k=(y2-y1)/(x2-x1)��
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
