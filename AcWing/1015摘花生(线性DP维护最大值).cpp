#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=105;

int T,n,m;
int w[N][N];//ά��Ȩֵ
int f[N][N];//ά���ߵ��㣨i��j�������ֵ

int main()
{
    scanf("%d",&T);//������������
    
    while(T--)
    {
        scanf("%d%d",&n,&m);//��������С
        
        for(int i=1;i<=n;i++)//����ͼ
            for(int j=1;j<=m;j++)
                scanf("%d",&w[i][j]);
                
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                f[i][j]=max(f[i-1][j],f[i][j-1])+w[i][j];//״̬ת�Ʒ���
                
        printf("%d\n",f[n][m]);//������
    }
    return 0;
}
