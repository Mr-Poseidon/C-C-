#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1000010;

int prime[N],cnt;
bool isp[N];

/*
线性筛证明： 
	c1代表被筛掉的合数，c2代表当前遇到的数，可能是合数、也可能是质数，假定都是合数
	p(j)代表最小的质数
	设：c1 = c2 * p(j)
	为何 c2 % p(j) == 0 即 c2是p(j)的倍数是跳出循环？？？
	代码：if(i%prime[j]==0)break;
	
	当不跳出循环时，则有 c1 = p(j+1) * c2
	由上述可知， c2 % p(j) == 0 设：c2 = p(j) * x 
	所以： c1 =  p(j+1) * c2 = p(j+1) * p(j) * x
	c1应该被p(j)筛掉，而不应该被p(j+1)筛掉，否则后面会出现重复筛掉的情况 
	此处的c1会在后面遇到更大的数的时候、被p(j)筛掉
	保证了每个数只会被它最小的质因数筛掉 
*/ 

void get_prime(int n)
{
    for(int i=2;i<=n;i++)//此处遍历所有的数
    {
        if(!isp[i])prime[cnt++]=i;
        
        for(int j=0;prime[j]<=n/i;j++)//遍历所有质数 
        {
            isp[prime[j]*i]=true;
            //一个数i是一个数num的最小质因子、那么i将会是num的所有倍数的最小质因子
            //prime[i]绝对是i的最小质因子，所以prime[i]同时也会是prime[j]*i的最小质因子
            //质数与本身互质，所以不会存在循环越界的情况 
            if(i%prime[j]==0)break;
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    
    get_prime(n);
    
    printf("%d",cnt);
    
    return 0;
}
