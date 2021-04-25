#include<iostream>
using namespace std;

typedef long long ll;

//注：本题注重对题目的推导、使其变成一个扩展欧几里得定理
/*
根据题意：a*x = m*y + b 
可得：a*x - m*y = b 
令：y' = -y
可得：a*x + m*y' = b 
若b是gcd(a,m)的倍数、则该题有解
本题右边b已经给出、
若想gcd(a,m)=b,即两边同时扩大b/gcd(a,m)倍
*/

int exgcd(int a,int b,int& x,int& y)//扩展欧几里得
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
        
        if(b%d!=0)puts("impossible");//b不是d的倍数、无解
        else printf("%d\n",(ll)x*(b/d)%m);//取模m使答案在m范围内
    }
    return 0;
}
