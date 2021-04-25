#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<unordered_map>
using namespace std;

typedef long long int ll;//出现取模、必须定义ll，避免数据溢出
const int mod=1e9+7;

unordered_map<int,int> primes;//用无序表维护质因数的次方
int n;

int main()
{
    
    cin>>n;
    while(n--)
    {
        int num;
        cin>>num;
        for(int i=2;i<=num/i;i++)//将每个数分解质因数
            while(num%i==0)
            {
                num/=i;//自除
                primes[i]++;//次方+1
            }
        if(num>1)primes[num]++;//如果存在最后一个大于sqrt(num)的质因数，记录
    }
    
    ll ans=1;
    for(unordered_map<int,int>::iterator it=primes.begin();it!=primes.end();it++)//遍历所有质因数
        ans=ans*(it->second+1)%mod;//计算约数的个数，所有质因数的次方+1相乘
    
    cout<<ans;//输出结果
    return 0;
}
