#include<cstdio>
#include<iostream>
using namespace std;

const int N=10;

//dg-diagonal�Խ���
//col[k]����k��k���б�ʹ�ù�
//dg[k]����k��k�����Խ����б�ʹ�ù�
//udg[k]����k��k�����Խ����б�ʹ�ù�
bool col[N],dg[2*N],udg[2*N];
char mp[N][N];
int n;



void dfs(int k)//���ѣ�k����ڼ���
{
    if(k==n)//������������
    {
        for(int i=0;i<n;i++)puts(mp[i]);
        puts("");
        return;
    }
    
    /*
        ���Խ���: y = x + b �� b = y - x, b����Ϊ����,������Ҫ�Ӹ�N��֤Ϊ����
        ���Խ��ߣ�y = x - b �� b = y + x
    */
    for(int i=0;i<n;i++)//i����ڼ���
    {
        if(!col[i] && !dg[i-k+N] && !udg[i+k])//������У����Ҹ������ڵ����Խ��ߺͷ��Խ��߶�û�ù�����������
        {
            col[i]=dg[i-k+N]=udg[i+k]=true;//�ı�״̬
            mp[k][i]='Q';
            dfs(k+1);
            mp[k][i]='.';
            col[i]=dg[i-k+N]=udg[i+k]=false;//�ָ�״̬
        }
    }
    return;
}


int main()
{
    scanf("%d",&n);
    
    //��ʼ��ͼ
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            mp[i][j]='.';
    
    dfs(0);
    
    return 0;
}

