#include<iostream>
using namespace std;

typedef unsigned long long ull;//unsigned long long 为 2^64,溢出自动取模

const int N=100010,P=131;//P为固定值，冲突几率最小，近乎没有

ull h[N],p[N];//h[]哈希值表，值必为0~2^64-1，p[]存储P的i次方值
char s[N];//字符串下标由1开始，0弃置不用

ull gethash(int l,int r)//获取区间[l,r]的子字符串的哈希值
{
    //由于低位的字符实际上是高位的哈希值，所以低位字符串要乘上P[r-l+1]
    return h[r]-h[l-1]*p[r-l+1];// r-(l-1)=r-l+1
}

int main()
{
    int n,m;
    cin>>n>>m;
    cin>>s+1;
    
    p[0]=1;//P的0次方为1
    for(int i=1;i<=n;i++)//计算字符串的哈希值
    {
        h[i]=h[i-1]*P+s[i];//字符串的哈希值不断由子字符串的哈希值构成
        p[i]=p[i-1]*P;//存储P的次方数
    }
    
    for(int i=0;i<m;i++)//查询
    {
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(gethash(l1,r1)==gethash(l2,r2))puts("Yes");
        else puts("No");
    }
    return 0;
}

