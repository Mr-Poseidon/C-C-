#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N=15;

int f[N][N];//f[i][j]维护有i位数，且最高位为j时的合法方案数
int l,r;//维护区间

void init()
{
    for(int i=0;i<=9;i++)f[1][i]=1;//只有一位数时，每一位数都是合法的
    
    for(int i=2;i<N;i++)//共有i位
        for(int j=0;j<=9;j++)//最高位为j
            for(int k=j;k<=9;k++)//大于等于j的情况
                f[i][j]+=f[i-1][k];
}


int dp(int n)
{
    if(n==0)return 1;//0的话也是一种合法方案
    
    vector<int> nums;
    while(n)nums.push_back(n%10),n/=10;
    
    int ans=0;//维护方案数
    int pre=0;//维护前面那一位数，最开始前面那一位数可以是0
    
    //数位dp在遍历每一位数的时候，都是不包含本身的，例如446，不能走到第二个4、才能保证后面的每一个数都是小于446的
    for(int i=nums.size()-1;i>=0;i--)//遍历每一位数
    {
        int x=nums[i];//取出本位数
        
        for(int j=pre;j<x;j++)//加上每一位合法的情况
            ans+=f[i+1][j];
        
        if(pre>x)break;//如果前面那位数大于本位数、这种情况不合法、直接跳出循环
        else pre=x;//否则记录前面那位数
        
        if(i==0)ans++;//遍历到最后一位、则代表n本身也是一种情况
    }
    
    return ans;//返回方案数
    
}
int main()
{
    init();//预处理
    
    while(cin>>l>>r)cout<<dp(r)-dp(l-1)<<endl;
    
    return 0;
}
