#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<unordered_map>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

int n;
unordered_map<int,int> primes;//维护质因数

int main()
{
    cin>>n;
    while(n--)//分解各个数的质因数
    {
        int num;
        cin>>num;
        for(int i=2;i<=num/i;i++)//遍历质因数
            while(num%i==0)
            {
                num/=i;//去掉一次质因子
                primes[i]++;//质因子的次幂+1
            }
        if(num>1)primes[num]++;//存在大于等于sqrt(num)的质因数
    }
    
    ll ans=1;
    for(unordered_map<int,int>::iterator it=primes.begin();it!=primes.end();it++)//遍历所有的质因数
    {
        int p=it->first,a=it->second;//p代表底数，a代表指数
        ll sum=1;
        while(a--)sum=(sum*p+1)%mod;//计算以p为底，0~a次幂的和
        ans=(ans*sum)%mod;//计算所有质因子和的乘积
    }
    cout<<ans;
    return 0;
}
