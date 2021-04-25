#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010;

/*
	若再维护一个p[N],代表第i个数结尾的子序列是由p[i]转移而来、
	用递归回溯即可得出最长上升子序列 
*/ 

int a[N];//a[]维护完整的序列
int f[N];//f[i]代表以a[i]结尾的前i个数的最大子序列的值
int n;

int main()
{
    //输入
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    
    for(int i=1;i<=n;i++)
    {
        f[i]=1;//每个数最少都是长度为1的子序列
        for(int j=1;j<i;j++)//注意此处不能包含i
            if(a[j]<a[i])//当a[j]<a[i]时，说明a[i]可以出现在a[j]后面
                f[i]=max(f[i],f[j]+1);//状态转移方程
    }
    
    int ans=0;
    for(int i=1;i<=n;i++)//遍历所有的情况找出最大值
        ans=max(ans,f[i]);
    printf("%d",ans);
    
    return 0;
}
