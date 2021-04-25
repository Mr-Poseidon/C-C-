#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N=5010;

int primes[N],cnt;//质数队列
bool isp[N];//是否是质数
int sum[N];//sum[i]维护第i个质数出现的次数

void get_primes(int num)//线性质数筛
{
    for(int i=2;i<=num;i++)
    {
        if(!isp[i])primes[cnt++]=i;
        for(int j=0;primes[j]<=num/i;j++)
        {
            isp[primes[j]*i]=true;
            if(i%primes[j]==0)break;
        }
    }
}

int get(int num,int p)//计算num!中质因子p出现的次数
{
    int ans=0;
    while(num)
    {
        ans+=num/p;//加上num!中含有质因子p的数的个数
        num/=p;
    }
    return ans;
}

vector<int> mul(vector<int> a,int b)//大数相乘
{
    vector<int> c;
    
    for(int i=0,t=0;i<a.size()||t;i++)
    {
        if(i<a.size())t+=a[i]*b;
        c.push_back(t%10);
        t/=10;
    }
    
    return c;
}

int main()
{
    int a,b;
    cin>>a>>b;
    
    get_primes(a);//筛出范围内的所有质数
    
    for(int i=0;i<cnt;i++)//遍历所有质因子，并计算在阶乘中该质因子出现的次数
    {
        int p=primes[i];
        sum[i]=get(a,p)-get(b,p)-get(a-b,p);//同一个质因子，相除即为相减
    }
    
    vector<int> ans;
    ans.push_back(1);
    
    for(int i=0;i<cnt;i++)//遍历质因子
        for(int j=0;j<sum[i];j++)//遍历质因子出现的次数
            ans=mul(ans,primes[i]);//大数乘
            
    for(int i=ans.size()-1;i>=0;i--)cout<<ans[i];//输出结果
    
    return 0;
}
