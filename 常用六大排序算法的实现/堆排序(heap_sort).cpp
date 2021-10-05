#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int n,m;
vector<int> heap;

// 从小到大排序建大根堆，因为根节点要放到最后面
// 从大到小排序建小根堆

//堆中，默认下标0弃置，下标1的元素为根节点


//大根堆，下沉操作
void push_down(vector<int>& heap,int size,int u)
{
    int t=u,left=u*2,right=u*2+1;
    if(left<=size && heap[left]>heap[t])t=left;//不越界，并且左子树较大
    if(right<=size && heap[right]>heap[t])t=right;//不越界，并且右子树较大
    if(t!=u)//如果存在更大的值
    {
        swap(heap[u],heap[t]);//交换
        push_down(heap,size,t);//下沉
    }
}

//大根堆，上浮操作
void push_up(vector<int>& heap,int u)
{
    while(u/2 && heap[u/2]<heap[u])//如果没有越界，并且父节点更小
    {
        swap(heap[u/2],heap[u]);//交换
        u/=2;//上移
    }
}

//堆排序
void heap_sort(vector<int>& heap,int size)
{
    int n=size;
    for(int i=1;i<=n;i++)push_up(heap,i);//建堆，像插入一样、上浮
    
    //堆排序
    for(int i=1;i<=n;i++)//排序n次
    {
        swap(heap[1],heap[size]);//将根节点（最大的数）放到最后面
        size--;//数量--
        push_down(heap,size,1);
    }
}


int main()
{
    cin>>n>>m;
    heap.resize(n+1);
    
    for(int i=1;i<=n;i++)cin>>heap[i];
    
    heap_sort(heap,n);//排序堆中的前n个数
    
    for(int i=1;i<=m;i++)cout<<heap[i]<<' ';
    return 0;
}


