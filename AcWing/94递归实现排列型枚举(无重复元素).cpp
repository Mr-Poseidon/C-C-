#include<cstdio>
using namespace std;

//����ȫ�����в������ظ���Ԫ��

const int N=10;

int path[N];
bool use[N];
int n;


void dfs(int k)//����
{
    if(k==n)//���
    {
        for(int i=0;i<n;i++)printf("%d ",path[i]);
        puts("");
        return;
    }
    
    for(int i=1;i<=n;i++)//�������ܵ����
    {
        if(!use[i])//i�����û���ù�
        {
            use[i]=true;
            path[k]=i;
            dfs(k+1);
            use[i]=false;
        }
    }
    return;
}

int main()
{
    
    scanf("%d",&n);
    
    dfs(0);
    
    return 0;
}

