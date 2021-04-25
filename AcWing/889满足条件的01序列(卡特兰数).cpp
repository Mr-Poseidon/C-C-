#include<iostream>
#include<algorithm>
using namespace std;

const int mod=1e9+7;
typedef long long ll;

//本题根据题意得出考察卡特兰数
//卡特兰数公式：C(2n,n)-C(2n,n-1) = 1/(n+1)*C(2n,n)

int qmi(int a,int k,int p)//快速幂
{
    int ans=1;
    while(k)
    {
        if(k&1)ans=(ll)ans*a%mod;
        a=(ll)a*a%mod;
        k>>=1;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    
    int ans=1;
    for(int i=1,j=2*n;i<=n;i++,j--)//根据定义求组合数
    {
        ans=(ll)ans*j%mod;
        ans=(ll)ans*qmi(i,mod-2,mod)%mod;
    }
    
    ans=(ll)ans*qmi(n+1,mod-2,mod)%mod;//乘上系数1/(n+1)、即(n+1)的逆元、同模求逆元
    
    cout<<ans;//输出答案
    return 0;
}
