#include<iostream>
using namespace std;

//扩展欧几里得定理：x*a + y*b = gcd(a,b) = gcd(b,a%b) 

//下一层的情况为： b*x1 + (a%b)*y1 = gcd(b,a%b) 
//            即：  b*x1 + ( a - a/b*b )*y1 = gcd(b,a%b)
//        展开得：b*x1 +  a*y1 - a/b * b *y1 = gcd(b,a%b) 
//        整理得：a*y1 + b*(x1-a/b*y1) = gcd(b,a%b)
//因为递归的时候x与y互换位置，所以，下层的x1=y,y1=x
//        带入得：a*x + b*(y-a/b*x) = gcd(b,a%b)
//所以本层x和y为：x=x , y=y-a/b*x 即 y-=a/b*x

//求出一组(x,y)，即可得出所有通解
//      令： gcd(a,b)=d 
//    则有： a*x + b*y = d 
//  构造得： a*x0 + b*y0 + a*b/d - a*b/d = d 
//    可得： a*(x0-b/d) + b*(y0+a/d) = d 
//即通解为： x = x0-b/d * k  ,  k为整数 
//           y = y0+a/d * k 
          

int exgcd(int a,int b,int& x,int& y)//此处x，y为引用传递
{
    if(b==0)
    {
        x=1,y=0;//b为0时、x=1,y=0为其中一组解
        return a;
    }
    
    int d=exgcd(b,a%b,y,x);//递归
    y-=a/b*x;//获取本层y的值
    return d;//返回最大公因数
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
