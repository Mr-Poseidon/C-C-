#include<iostream>
#include<algorithm>
using namespace std;

const int N=100010;

int f[N][2];//f[i][0]-不抢，f[i][1]-抢
int n;

//状态自动机，合法的情况初始化为0，不合法的情况初始化为-INF,代表该点不可到达

//本次不抢：max(前一次抢，不抢)
//本次抢：前一次不抢+本次权值

int main()
{
    int T;
    cin>>T;
    while(T--)//遍历数据组数
    {
        cin>>n;
        
        //初始化状态
        f[0][0]=0;//不抢是合法的
        f[0][1]=-0x3f3f3f3f;//抢是不合法的
        
        for(int i=1;i<=n;i++)//自动机迭代
        {
            int w;
            cin>>w;//输入权值
            
            f[i][0]=max(f[i-1][0],f[i-1][1]);//不抢
            f[i][1]=f[i-1][0]+w;//抢
        }
        
        cout<<max(f[n][0],f[n][1])<<endl;//输出结果
    }
    return 0;
}
