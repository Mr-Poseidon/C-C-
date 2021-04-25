#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

const int N=15;

int f[N][N];//f[i][j]维护共有i位数、且第i位为j的合法方案数
int l,r;

//预处理
void init()
{
    for(int i=0;i<=9;i++)f[1][i]=1;//只有一位数时，每个数都是合法的、因为0参与转移、所以这里设置0也是合法的
    
    for(int i=2;i<N;i++)//遍历i位数
        for(int j=0;j<=9;j++)//最高位为0
            for(int k=0;k<=9;k++)//遍历前一位
                if(abs(j-k)>=2)//合法就转移
                    f[i][j]+=f[i-1][k];//状态转移方程
}

//计算[0,n]的合法方案数
int dp(int n)
{
    if(n==0)return 0;//0不是合法方案
    
    //取出每一位数
    vector<int> nums;
    while(n)nums.push_back(n%10),n/=10;
    
    int ans=0;//维护方案数
    int pre=-2;//维护前面一位数，因为最开始每一位数都合法、所以初始化成-2
    
    for(int i=nums.size()-1;i>=0;i--)//遍历每一位数
    {
        int x=nums[i];//取出本位数
        
        for(int j=(i==nums.size()-1)?1:0;j<x;j++)//如果是首位、不能为0、要从1开始枚举，并且不能包括x本身
            if(abs(j-pre)>=2)//如果和前一位数差的绝对值大于等于2，即为合法
                ans+=f[i+1][j];//加上方案
        
        if(abs(x-pre)>=2)pre=x;//如果本位数和前一位数没有冲突、记录本位数
        else break;//否则直接结束
        
        if(i==0)ans++;//如果是遍历到最后一位数、说明本身也是一种方案，所以+1
    }
    
    //特殊处理所有包含前导零的情况，至少含有一个前导零、所以最多只有nums.size()-1位
    for(int i=1;i<nums.size();i++)
        for(int j=1;j<=9;j++)//枚举所有不含前导零的情况
            ans+=f[i][j];
    
    return ans;//返回结果
}

int main()
{
    init();//预处理
    
    cin>>l>>r;//输入
    cout<<dp(r)-dp(l-1)<<endl;//输出
    
    return 0;
}
