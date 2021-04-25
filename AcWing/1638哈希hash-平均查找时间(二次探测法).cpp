#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N=10005,null=0x3f3f3f3f;
typedef pair<int,int> PII;

int ms,n,m;
int h[N];

PII find(int x)//first����λ�ã�-1�����Ѳ����� second����̽������
{
    int step=0;
    for(int i=0;i<ms;i++)
    {
        int k=(x%ms+i*i)%ms;
        if(h[k]==null || h[k]==x)
            return {k,step+1};
        step++;
    }
    return {-1,step+1};
}

int main()
{
    cin>>ms>>n>>m;
    
    for(int i=ms;;i++)//�Ҵ���ɢ�б��С����С����
    {
        bool f=true;
        for(int j=2;j*j<=i;j++)
            if(i%j==0)
            {
                f=false;
                break;
            }
        if(f)
        {
            ms=i;
            break;
        }
    }
    
    memset(h,0x3f,sizeof(h));//ɢ�б��ʼ��
    
    int x;
    while(n--)
    {
        cin>>x;
        PII p=find(x);//����
        if(p.first!=-1)h[p.first]=x;//���Բ�������
        else printf("%d cannot be inserted.\n",x);
    }
    
    int ans=0;
    for(int i=0;i<m;i++)
    {
        cin>>x;
        PII p=find(x);//����
        ans+=p.second;//����̽���Ĵ���
    }
    printf("%.1f",ans*1.0/m);
    return 0;
}
