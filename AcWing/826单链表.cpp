#include<iostream>
using namespace std;

const int N=100010;

int n;

int head;//head代表头节点
int e[N],ne[N];//e[]存值,ne[]存下一个节点的下标
int idx;//代表内存下标

void init()//单链表初始化
{
    head=-1;//-1代表尾节点
    idx=0;//内存下标为0
}

void insert_to_head(int x)//向头节点后面插入节点
{
    e[idx]=x, ne[idx]=head, head=idx++;//记得idx要后移
}

void insert(int k,int x)//向k节点的后面插入值为x的节点
{
    e[idx]=x, ne[idx]=ne[k], ne[k]=idx++;
}

void remove(int k)//删除k节点
{
    ne[k]=ne[ne[k]];
}

int main()
{
    init();//记得初始化
    
    cin>>n;
    while(n--)
    {
        int k,x;
        char op;
        cin>>op;
        
        if(op=='H')//向头节点插入
        {
            cin>>x;
            insert_to_head(x);
        }
        else if(op=='D')//删除
        {
            cin>>k;
            if(k==0)head=ne[head];//删除头节点
            else remove(k-1);//删除普通节点
        }
        else 
        {
            cin>>k>>x;
            insert(k-1,x);//在k节点后面插入值为x的节点
        }
    }
    
    //输出
    for(int i=head;i!=-1;i=ne[i])cout<<e[i]<<' ';
    cout<<endl;
    return 0;
}
