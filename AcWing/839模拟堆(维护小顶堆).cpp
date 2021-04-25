#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=100010;

//此题维护小顶堆
//h[]为堆
//ph[k]代表第k个插入的数在堆中的下标-pointer to heap(指向堆)
//hp[k]代表堆下标为k的数是第几次插入的-heap to pointer(从堆中指出来)
int h[N],hp[N],ph[N],sizes;

void heap_swap(int a,int b)
{
    swap(hp[a],hp[b]);//插入的次序交换
    swap(ph[hp[a]],ph[hp[b]]);//在堆中的下标交换
    swap(h[a],h[b]);//值交换
}

void down(int k)//向下更新
{
    int t=k;//设t为当前三个节点中最小值的下标 
    if(k*2<=sizes && h[k*2]<h[t])t=k*2;//和左子树比较
    if(k*2+1<=sizes && h[k*2+1]<h[t])t=k*2+1;//和右子树比较
    if(t!=k)//存在需要交换最小值
    {
        heap_swap(t,k);//交换
        down(t);//递归
    }
}

void up(int k)//向上更新
{
    while(k/2 && h[k/2]>h[k])//父节点大于子节点
    {
        heap_swap(k/2,k);//交换
        k/=2;//向上走
    }
}

void erase(int k)//删除操作
{
    heap_swap(k,sizes);//尾节点覆盖需要删除的节点
    sizes--;//堆数量--
    //实际更新操作只会执行一种，值比原值小则向上更新、比原值大则向下更新
    down(k),up(k);//更新
}


int main()
{
    int n;
    scanf("%d",&n);
    
    char op[10];
    int k,x,m=0;//m代表第m次插入
    
    for(int i=1;i<=n;i++)
    {
        scanf("%s",op);
        
        if(!strcmp(op,"I"))
        {
            scanf("%d",&x);
            sizes++;
            m++;
            
            h[sizes]=x;
            //up更新中涉及交换、所以先记录，再更新
            ph[m]=sizes;//第m次插入的数在堆中的下标为sizes
            hp[sizes]=m;//堆下标为sizes的数为第m次插入的数
            up(sizes);//插入操作因为插在堆底，只需向上更新
        }
        else if(!strcmp(op,"PM"))printf("%d\n",h[1]);//输出堆中的最小值，即堆顶
        else if(!strcmp(op,"DM"))erase(1);//删除堆顶
        else if(!strcmp(op,"D"))//删除第k次插入的值
        {
            scanf("%d",&k);
            erase(ph[k]);//第k次插入的值在堆中的小标为ph[k]
        }
        else if(!strcmp(op,"C"))//修改第k次插入的值为x
        {
            scanf("%d%d",&k,&x);
            //修改堆中元素的值并不会对插入的次序和堆下标造成影响
            k=ph[k];//找出第k次插入的数在堆中的下标
            h[k]=x;//修改
            //实际更新操作只会执行一种，值比原值小则向上更新、比原值大则向下更新
            down(k),up(k);//更新堆
        }
    }
    return 0;
}
