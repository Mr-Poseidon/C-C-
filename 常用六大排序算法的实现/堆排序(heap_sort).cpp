#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int n,m;
vector<int> heap;

// ��С�������򽨴���ѣ���Ϊ���ڵ�Ҫ�ŵ������
// �Ӵ�С����С����

//���У�Ĭ���±�0���ã��±�1��Ԫ��Ϊ���ڵ�


//����ѣ��³�����
void push_down(vector<int>& heap,int size,int u)
{
    int t=u,left=u*2,right=u*2+1;
    if(left<=size && heap[left]>heap[t])t=left;//��Խ�磬�����������ϴ�
    if(right<=size && heap[right]>heap[t])t=right;//��Խ�磬�����������ϴ�
    if(t!=u)//������ڸ����ֵ
    {
        swap(heap[u],heap[t]);//����
        push_down(heap,size,t);//�³�
    }
}

//����ѣ��ϸ�����
void push_up(vector<int>& heap,int u)
{
    while(u/2 && heap[u/2]<heap[u])//���û��Խ�磬���Ҹ��ڵ��С
    {
        swap(heap[u/2],heap[u]);//����
        u/=2;//����
    }
}

//������
void heap_sort(vector<int>& heap,int size)
{
    int n=size;
    for(int i=1;i<=n;i++)push_up(heap,i);//���ѣ������һ�����ϸ�
    
    //������
    for(int i=1;i<=n;i++)//����n��
    {
        swap(heap[1],heap[size]);//�����ڵ㣨���������ŵ������
        size--;//����--
        push_down(heap,size,1);
    }
}


int main()
{
    cin>>n>>m;
    heap.resize(n+1);
    
    for(int i=1;i<=n;i++)cin>>heap[i];
    
    heap_sort(heap,n);//������е�ǰn����
    
    for(int i=1;i<=m;i++)cout<<heap[i]<<' ';
    return 0;
}


