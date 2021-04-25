#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1000010;

bool isp[N];//维护是不是质数、默认都是质数
int prime[N],cnt;//prime[]维护质数队列，cnt代表质数的个数
int n;


void get_prime(int num)
{
    for(int i=2;i<=num;i++)//遍历整个数组
        if(!isp[i])//是质数
        {
            prime[cnt++]=i;//入队
            for(int j=i+i;j<=n;j+=i)isp[j]=true;//去掉质数所有的倍数
        }
}


int main()
{
    scanf("%d",&n);
    
    get_prime(n);
    
    printf("%d",cnt);
    
    return 0;
}

