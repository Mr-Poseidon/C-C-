#include<iostream>
#include<algorithm>
using namespace std;


/*
    除一个数就相当于乘上一个数的逆元
    由于模数为质数、根据费马小定理，利用快速幂求num的逆元为：qmi(num,mod-2,mod);
*/
typedef long long ll;
const int N=100010,mod=1e9+7;

int fact[N],infact[N];//fact[]维护一个数的阶乘，infact[]维护一个数的逆元阶层 

int qmi(int a,int k,int p)//快速幂 
{
    int ans=1;
    while(k)
    {
        if(k&1)ans=(ll)ans*a%p;
        k>>=1;
        a=(ll)a*a%p;
    }
    return ans;
}


void init()//初始化 
{
    fact[0]=infact[0]=1;//0的阶层和逆元阶层都为 1 
    for(int i=1;i<N;i++)
    {
        fact[i]=(ll)fact[i-1]*i%mod;
        //求出逆元后还要乘上前一个数的逆元阶乘然后再取模
        infact[i]=(ll)infact[i-1]*qmi(i,mod-2,mod)%mod;
    }
}
int main()
{
    init();
    
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        //根据阶乘公式c(a,b)=a!/(b!*(a-b)!),除一个数就是乘上一个数的逆元
        cout<<(ll)fact[a]*infact[b]%mod*infact[a-b]%mod<<endl;
    }
    return 0;
}
