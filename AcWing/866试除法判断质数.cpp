#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int n;

bool isprime(int n)//判断质数
{
    if(n<2)return false;
    for(int i=2;i<=n/i;i++)//注意此处写成:i<=n/i,避免出现数据溢出
        if(n%i==0)
            return false;
    return true;
}

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        int t;
        scanf("%d",&t);
        if(isprime(t))puts("Yes");
        else puts("No");
    }
    return 0;
}
