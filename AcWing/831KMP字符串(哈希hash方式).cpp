#include<iostream>
#include<cstdio> 
using namespace std;

typedef unsigned long long ull;

const int N=1000003,P=131;
ull h[N],p[N];//h[]存模式串的哈希表，p[]存进制的次方数

int n,m;
char s[N],ps[N];//s[]模式串，ps[]模板串

ull gethash(int l,int r)//获取模式串某段子串的哈希值
{
    return h[r]-h[l-1]*p[r-l+1];
}

int main()
{
    scanf("%d%s",&n,ps+1);//输入模板串
    scanf("%d%s",&m,s+1);//输入模式串
    
    p[0]=1;
    for(int i=1;i<=m;i++)//计算模式串的哈希值表
    {
        h[i]=h[i-1]*P+s[i];
        p[i]=p[i-1]*P;
    }
    
    ull psh=0;
    for(int i=1;i<=n;i++)//计算模板串的哈希值
        psh=psh*P+ps[i];
    
    for(int i=1;i+n-1<=m;i++)//匹配
        if(gethash(i,i+n-1)==psh)
            printf("%d ",i-1);
    
    return 0;
}
 
