#include<iostream>
using namespace std;

//��չŷ����ö���x*a + y*b = gcd(a,b) = gcd(b,a%b) 

//��һ������Ϊ�� b*x1 + (a%b)*y1 = gcd(b,a%b) 
//            ����  b*x1 + ( a - a/b*b )*y1 = gcd(b,a%b)
//        չ���ã�b*x1 +  a*y1 - a/b * b *y1 = gcd(b,a%b) 
//        ����ã�a*y1 + b*(x1-a/b*y1) = gcd(b,a%b)
//��Ϊ�ݹ��ʱ��x��y����λ�ã����ԣ��²��x1=y,y1=x
//        ����ã�a*x + b*(y-a/b*x) = gcd(b,a%b)
//���Ա���x��yΪ��x=x , y=y-a/b*x �� y-=a/b*x

//���һ��(x,y)�����ɵó�����ͨ��
//      � gcd(a,b)=d 
//    ���У� a*x + b*y = d 
//  ����ã� a*x0 + b*y0 + a*b/d - a*b/d = d 
//    �ɵã� a*(x0-b/d) + b*(y0+a/d) = d 
//��ͨ��Ϊ�� x = x0-b/d * k  ,  kΪ���� 
//           y = y0+a/d * k 
          

int exgcd(int a,int b,int& x,int& y)//�˴�x��yΪ���ô���
{
    if(b==0)
    {
        x=1,y=0;//bΪ0ʱ��x=1,y=0Ϊ����һ���
        return a;
    }
    
    int d=exgcd(b,a%b,y,x);//�ݹ�
    y-=a/b*x;//��ȡ����y��ֵ
    return d;//�����������
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,b,x,y;
        scanf("%d%d",&a,&b);
        exgcd(a,b,x,y);
        printf("%d %d\n",x,y);
    }
    return 0;
}
