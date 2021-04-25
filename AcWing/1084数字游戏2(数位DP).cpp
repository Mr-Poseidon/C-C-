#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N=11,M=110;

int f[N][N][M];
int l,r,P;

int mod(int x,int y)//取模函数，使得取出来的模全部都是正数
{
    return (x%y+y)%y;
}

void init()
{
    memset(f,0,sizeof f);//多组测试数据、要初始化表
    
    for(int i=0;i<=9;i++)f[1][i][mod(i,P)]++;//只有一位数字时候的情况
    
    for(int i=2;i<N;i++)//共有i位数字
        for(int j=0;j<=9;j++)//最高位为j
            for(int k=0;k<P;k++)//modP的余数为k
                for(int x=0;x<N;x++)//下一位数字是x
                    f[i][j][k]+=f[i-1][x][mod(k-j,P)];
}

int dp(int n)
{
    if(n==0)return 1;//0模上任何数都是0、都是一种合法方案
    
    vector<int> nums;//取出每一位数字
    while(n)nums.push_back(n%10),n/=10;
    
    int ans=0;//维护方案数
    int pre=0;//维护前面的数字的和
    
    for(int i=nums.size()-1;i>=0;i--)//遍历每一位数字
    {
        int x=nums[i];//取出改为数字
        
        for(int j=0;j<x;j++)//如果该位数字填小于x的情况
            ans+=f[i+1][j][mod(-pre,P)];
        
        pre+=x;//x加入前面的数字和
        
        if(i==0 && pre%P==0)ans++;//本身也是一种合法方案的情况
    }
    
    return ans;//返回结果
}

int main()
{
    while(cin>>l>>r>>P)//输入数据
    {
        init();//初始化
        
        cout<<dp(r)-dp(l-1)<<endl;//输出
    }
    
    return 0;
}
