#include<iostream>
#include<cstring>
using namespace std;

const int N=200003;//开放寻址法卡空间一般开元素个数的2~3倍,并且应该为质数(质数冲突概率最低)
const int null=0x3f3f3f3f;//代表无穷大,代表这个位置为空

int h[N];//哈希表

int find(int x)//查询x存放的位置或者x应该存放的位置
{
    int k=(x%N+N)%N;//哈希算法
    
    //一直寻找，直到找到x或者null位置
    while(h[k]!=null && h[k]!=x)
    {
        k++;
        if(k==N)k=0;//回头
    }
    return k;//返回的k代表的可能是x的位置,也有可能是null位置(x应该存放的位置)
}

int main()
{
    memset(h,0x3f,sizeof(h));//初始化整个哈希表
    int n;
    cin>>n;
    while(n--)
    {
        char op[2];
        int x;
        
        scanf("%s%d",&op,&x);
        
        int k=find(x);//查找x应该存放的位置
        
        if(op[0]=='I')h[k]=x;//插入
        else
        {
            if(h[k]!=null)cout<<"Yes"<<endl;//若该位置不为空,则x存在于哈希表中
            else cout<<"No"<<endl;
        }
    }
    return 0;
}


