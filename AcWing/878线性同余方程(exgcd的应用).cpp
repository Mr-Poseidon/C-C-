#include<iostream>
using namespace std;

typedef long long ll;

//ע������ע�ض���Ŀ���Ƶ���ʹ����һ����չŷ����ö���
/*
�������⣺a*x = m*y + b 
�ɵã�a*x - m*y = b 
�y' = -y
�ɵã�a*x + m*y' = b 
��b��gcd(a,m)�ı�����������н�
�����ұ�b�Ѿ�������
����gcd(a,m)=b,������ͬʱ����b/gcd(a,m)��
*/

int exgcd(int a,int b,int& x,int& y)//��չŷ�����
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,b,m;
        scanf("%d%d%d",&a,&b,&m);
        int x,y;
        int d=exgcd(a,m,x,y);
        
        if(b%d!=0)puts("impossible");//b����d�ı������޽�
        else printf("%d\n",(ll)x*(b/d)%m);//ȡģmʹ����m��Χ��
    }
    return 0;
}
