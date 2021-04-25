#include<iostream>
#include<algorithm>
using namespace std;

const int N=100010;

int h[N],sizes;

void down(int k)//向下递归
{
    int t=k;
    if(k*2<=sizes && h[k*2]<h[t])t=k*2;//判断左子树是否小于根
    if(k*2+1<=sizes && h[k*2+1]<h[t])t=k*2+1;//判断右子树是否小于根或左子树
    if(t!=k)//出现小的情况
    {
        swap(h[k],h[t]);//交换
        down(t);//递归
    }
}

void up(int k)//向上遍历
{
    while(k/2>=0 && h[k/2]>h[k])
    {
        swap(h[k/2],h[k]);
        k/=2;
    }
}

void erase(int k)//删除操作
{
    h[k]=h[sizes];//将堆底换到删除的位置
    sizes--;//堆数量--
    down(k);//从该位置向下递归
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    //构造堆
    for(int i=1;i<=n;i++)cin>>h[i];//将所有元素输入数组模拟的堆中
    sizes=n;//堆数量赋值
    
    //时间复杂度O(N)
    for(int i=n/2;i;i--)down(i);//对初始化
    
    while(m--)//删除操作
    {
        cout<<h[1]<<" ";
        erase(1);
    }
    return 0;
}
