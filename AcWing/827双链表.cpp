#include<iostream>
#include<string>
using namespace std;

const int N=100010;

//e[]用来存值，l[]用来存左端点，r[]用来存右端点
int e[N],l[N],r[N];
int idx;//内存下标

void init()//初始化链表
{
    //0代表左端点,1代表右端点
    r[0]=1;
    l[1]=0;
    idx=2;//由于0,1背占用,idx由2开始
}

void L(int x)//从左端点插入
{
    //先处理新的节点
    e[idx]=x;
    l[idx]=0;
    r[idx]=r[0];
    
    l[r[0]]=idx;
    r[0]=idx;
    idx++;
}

void R(int x)//从右端点插入
{
    //先处理新的节点
    e[idx]=x;
    l[idx]=l[1];
    r[idx]=1;
    
    r[l[1]]=idx;
    l[1]=idx;
    idx++;
}

void insert(int k,int x)//在k的右边插入,若在k的左边插入则为k的上一个节点的右边insert(l[k],x)
{
    e[idx]=x;
    l[idx]=k;
    r[idx]=r[k];
    l[r[k]]=idx;
    r[k]=idx;
    idx++;
}

void remove(int k)
{
    r[l[k]]=r[k];
    l[r[k]]=l[k];
}

int main()
{
    init();//初始化 
    
    int n;
    cin>>n;
    while(n--)
    {
        int k,x;
        string op;
        cin>>op;
        
        if(op=="L")//左端点插入
        {
            cin>>x;
            L(x);
        }
        else if(op=="R")//右端点插入
        {
            cin>>x;
            R(x);
        }
        else if(op=="IL")//在k点左边插入
        {
            cin>>k>>x;
            //因为下标idx由2开始，即第一个插入的数为2,第二个插入的数为3,所以k++
            insert(l[k+1],x);
        }
        else if(op=="IR")//在k点右边插入
        {
            cin>>k>>x;
            //因为下标idx由2开始，即第一个插入的数为2,第二个插入的数为3,所以k++
            insert(k+1,x);
        }
        else//删除k点
        {
            cin>>k;
            //因为下标idx由2开始，即第一个插入的数为2,第二个插入的数为3,所以k++
            remove(k+1);
        }
    }
    
    for(int i=r[0];i!=1;i=r[i])cout<<e[i]<<" ";//输出
    cout<<endl;
    return 0;
}


