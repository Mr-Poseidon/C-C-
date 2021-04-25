#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N=18;

int w[N],n,W;//w[i]ά����iֻè��Ȩֵ����nֻè���³��������W

int gw[N];//ά����iֻ�³���Ŀǰ��������
int gc,ans;//gcά��Ŀǰ����gc���³���ansά�����ٵ��³�����

void dfs(int kk)
{
    if(gc>=ans)return;//����³����Ѿ����ڵ�����С���������ֹͣ����
    if(kk==n)//�������è��������
    {
        ans=min(ans,gc);//ά����Сֵ
        return;//����
    }
    
    for(int i=0;i<gc;i++)//����ÿһ���³������
        if(gw[i]+w[kk]<=W)//�����kkֻè���԰����ڵ�i���³���
        {
            gw[i]+=w[kk];//���
            dfs(kk+1);//����
            gw[i]-=w[kk];//ȡ�����
        }

    //��һ���µ��³�
    gw[gc]+=w[kk];//���
    gc++;//�³�����+1
    dfs(kk+1);//����
    gc--;//�ָ��³�����
    gw[gc]-=w[kk];//ȡ�����
    
    return;
}

int main()
{
    cin>>n>>W;//����
    for(int i=0;i<n;i++)cin>>w[i];
    
    gc=0;//�³�������ʼ��
    ans=n;//�������nֻ�³�
    dfs(0);//����
    
    cout<<ans;//������
    return 0;
}

