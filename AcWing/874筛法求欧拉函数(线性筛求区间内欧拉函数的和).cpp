#include<iostream>
#include<cstdio>
using namespace std;

typedef long long ll;//所有欧拉函数的和比较大、避免数据溢出
const int N=1000010;

int primes[N],cnt;
int phi[N];
bool isp[N];


ll get_eulers(int num)
{
    phi[1]=1;//1的欧拉函数为1，因为1和本身互质
    for(int i=2;i<=num;i++)//遍历2~N之间所有的数
    {
        if(!isp[i])//是质数
        {
            primes[cnt++]=i;//入队
            phi[i]=i-1;//质数的欧拉函数为i-1
        }
        for(int j=0;primes[j]<=num/i;j++)//遍历所有的质数
        {
            isp[ i * primes[j] ]=true;//去除以primes[j]为最小质因子的合数
            
            if(i%primes[j]==0)//primes[j]是i的最小质因子、重点、避免对后面的数重复处理
            {
                phi[ i * primes[j] ]=phi[i]*primes[j];
                break;//线性筛优化 
            }
            else phi[ i * primes[j] ]=phi[i]*(primes[j]-1);
        }
    }
    
    ll sum=0;//计算所有欧拉函数的和
    for(int i=1;i<=num;i++)sum+=phi[i];
    return sum;
}

int main()
{
    int n;
    cin>>n;
    cout<<get_eulers(n)<<endl;//获取1~N之间所有数的欧拉函数之和
    return 0;
}
