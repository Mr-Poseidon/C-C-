#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=110;

int a[N];
int n;
int f[N],g[N];//f[]ά������������У�g[]ά����½�������
int ans;

void dfs(int i,int su,int sd)//����
{
    if(su+sd>=ans)return;//ע��˴���֦����su+sd>n�ᳬʱ,ע����>=,����ûдҲ��ʱ
    if(i==n)//�յ�
    {
        ans=su+sd;
        return;
    }
    
    int k=0,t;
    while(k<su && f[k]>=a[i])k++;//���ҿ��Բ��������
    t=f[k];//�����ֳ�
    f[k]=a[i];//����
    if(k==su) dfs(i+1,su+1,sd);//����
    else dfs(i+1,su,sd);
    f[k]=t;//�ָ��ֳ�

    
    k=0;
    while(k<sd && g[k]<=a[i])k++;//���ҿ��Բ��������
    t=g[k];//�����ֳ�
    g[k]=a[i];//����
    if(k==sd) dfs(i+1,su,sd+1);//����
    else dfs(i+1,su,sd);
    g[k]=t;//�ָ�
}

int main()
{
    while(cin>>n && n)
    {
        for(int i=0;i<n;i++)cin>>a[i];
        
        ans=n;//��ʼ����Сֵ
        dfs(0,0,0);//����
        
        cout<<ans<<endl;//������
    }
    return 0;
}
