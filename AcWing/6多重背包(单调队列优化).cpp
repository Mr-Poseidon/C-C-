/*
经典的滑动窗口问题（单调队列问题）
滑动窗口未优化：(n-k+1)(k-1)=nk  --数值之间重复比较 
滑动窗口优化：  (n)=n            --数值之间比较的时候直接排除，避免了重复比较的可能 

将所有的 m%v 余数相同的归为一组，每一组中，数值之间的偏移量为 w
每一组只需要计算一次 在物品数量范围内的最优解，结合偏移量，即可得出每一组的结果

优化比较：
 
      未优化：	n*m*s                --m为背包体积 
  二进制优化：	n*m*log(s) 
单调队列优化：	n*v*s                --v为物品体积，s为可买数量 
*/ 


#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

const int N=20005;
int dp[N],pre[N],q[N];//单调队列维护元素的下标 

int n,m;
int v,w,s;

int main()
{
    cin>>n>>m;
    for(int i=0;i<=m;i++)
        dp[i]=0;
    
    for(int i=1;i<=n;i++)//物品枚举
    {
        cin>>v>>w>>s;
        memcpy(pre,dp,sizeof(dp));
        for(int j=0;j<v;j++)//体积余数枚举
        {
            //单调队列优化部分
            int head = 0, tail = -1;
            for (int k = j; k <= m; k += v) 
            {
				// 出队
                if (head <= tail && k - s*v > q[head]) ++head;

				// 入队，从队尾开始，将小于本元素的元素去掉 
                while (head <= tail && pre[q[tail]] - (q[tail] - j)/v * w <= pre[k] - (k - j)/v * w)
                    --tail;
				
				// 求最大值 
                if (head <= tail)
                    dp[k] = max(dp[k], pre[q[head]] + (k - q[head])/v * w);
				
				// 入队 
                q[++tail] = k;
            }
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}


//-------------------------------------分割线---------------------------------------


#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=20010;

/*单调队列优化重点：
    q[hh]队头下标，即为 背包体积
    q[tt-1]队尾下标，即为 背包体积
    
    pre[ q[hh] ] 队头的值，维护的最大价值
    pre[ q[tt-1] ] 队尾的值，维护的最大价值
    
    s*v 代表距离
    注：单调队列优化背包 和 滑动窗口 问题不同
        滑动窗口必须 k-s*w 整个窗口都进入才会有结果
        而背包问题不用整个窗口都进入 也要 存在更新，即hh<tt,窗口内有元素就更新
        
    pre[q[tt-1]] - (q[tt-1]-j)/v*w 代表 队尾的实际最大价值
    pre[k] - (k-j)/v*w 代表 目前元素的实际最大价值
    此处为相对比较
    
    (k-q[hh])/v*w 代表 k到q[hh]增加的价值
    
*/

int pre[N],f[N];//维护滚动数组
int q[N],hh,tt;//维护单调队列、维护的是元素的下标
int n,m;

int main()
{
    cin>>n>>m;
    
    for(int i=0;i<n;i++)
    {
        int v,w,s;
        cin>>v>>w>>s;
        
        memcpy(pre,f,sizeof f);//记录上一步
        
        for(int j=0;j<v;j++)//遍历偏移量、即为 mod v 的余数
        {
            hh=0,tt=0;
            for(int k=j;k<=m;k+=v)//遍历涉及到的体积、单调队列优化
            {
                //出队，注：此处要<号比较出队，不能用==，避免跳步
                if(hh<tt && q[hh]<k-s*v)hh++;
                //单调队列处理尾部元素
                while(hh<tt && pre[q[tt-1]] - (q[tt-1]-j)/v*w <= pre[k] - (k-j)/v*w )tt--;
                //                不拿 ，  拿
                if(hh<tt)f[k]=max(f[k],pre[q[hh]]+(k-q[hh])/v*w);
                q[tt++]=k;//入队
            }
        } 
    }
    cout<<f[m]<<endl;//输出结果
    return 0;
}
 
