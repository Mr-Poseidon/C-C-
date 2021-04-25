#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N=150010;
typedef pair<int,int> PII;

int h[N],e[N],w[N],ne[N],idx;//e[]������һ���㣬w[]����õ㵽��һ����ľ���
int dis[N];//dis[]������������е�ľ���
bool vis[N];//�ж��Ƿ���ʹ�
int n,m;

int insert(int a,int b,int c)//����ߺ�Ȩֵ
{
    //b������һ���㡢c����a��b�ľ���
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

//���Ż���dijkstra�㷨ʱ�临�Ӷ�ΪO(MlogM)
//���㷨�������ڴ��ڸ�Ȩ����ͼ�С�����������ѭ�� 
int dijkstra(int a,int b)//a������㣬b�����յ�
{
    //��ʼ������ͷ������
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    dis[a]=0;//������Ϊ0
    
    //��Ϊvector��β��������������greater<>,ע���queue��β����ͷ�����Ľṹ���ֿ���
    priority_queue<PII,vector<PII>,greater<PII>> heap;//����һ��С����
    heap.push({0,a});//���
    
    while(!heap.empty())
    {
        PII t=heap.top();
        heap.pop();
        
        int distance=t.first,v=t.second;
        if(vis[v])continue;//����õ���ʹ�,����
        vis[v]=true;//���
        
        //�˲�����ʱ�临�Ӷ�ΪO(M)����Ϊ�ܹ�ֻ��M����
        for(int i=h[v];i!=-1;i=ne[i])//�����õ���Ե�������е�
        {
            int j=e[i];//��һ����
            if(dis[j]>distance+w[i])//������㵽��һ���������̣�����־�����̵�ԭ���Ǵ���������
            {
                dis[j]=distance+w[i];//����
                heap.push({dis[j],j});//��ӣ��ò���ʱ�临�Ӷ�ΪO(logM)
            }
        }
    }
    
    if(dis[b]==0x3f3f3f3f)return -1;//��������̾���
    else return dis[b];
}



int main()
{
    memset(h,-1,sizeof(h));//��ʼ���ڽӱ�
    
    scanf("%d%d",&n,&m);//��������ͱ���
    
    while(m--)//����ߺ�Ȩֵ
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        insert(a,b,c);//�����
    }
    
    int t=dijkstra(1,n);//������̾���
    
    printf("%d",t);
    return 0;
}
