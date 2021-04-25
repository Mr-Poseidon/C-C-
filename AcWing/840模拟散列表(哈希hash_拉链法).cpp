#include<iostream>
#include<cstring>
using namespace std;

const int N=100003;

//设置链表末尾为0，所以idx由1开始
int h[N],e[N],ne[N],idx=1;//h[]代表表头,e[]代表值,ne[]代表下一个值的坐标

void insert(int x)//插入
{
    int k=(x%N+N)%N;//哈希算法
    
    e[idx]=x,ne[idx]=h[k],h[k]=idx++;
}

bool find(int x)//查询
{
    int k=(x%N+N)%N;//哈希算法
    
    for(int i=h[k];i!=0;i=ne[i])//遍历链表
        if(e[i]==x)
            return true;//存在
    return false;//不存在
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        char op[2];
        int x;
        
        scanf("%s",&op);
        if(op[0]=='I')
        {
            cin>>x;
            insert(x);
        }
        else
        {
            cin>>x;
            if(find(x))cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}


