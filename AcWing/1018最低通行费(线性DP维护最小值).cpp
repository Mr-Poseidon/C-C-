#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=105;

int w[N][N];//ά������ķ���
int f[N][N];//ά���������Сֵ
int n;

int main()
{
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&w[i][j]);
    
    memset(f,0x3f,sizeof f);//ά����Сֵ����ʼ��Ϊ���ֵ
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==1 && j==1)f[i][j]=w[i][j];//��һ��������Сֵ���Ƿ���
            else
            {
                //���Ʊ߽磬������Ŀ�������ơ�����ֻ�� ���� ���� ���� ��
                if(i>1)f[i][j]=min(f[i][j],f[i-1][j]);//������������
                if(j>1)f[i][j]=min(f[i][j],f[i][j-1]);//������߹���
                f[i][j]+=w[i][j];//���ϱ�����ķ���
            }

    printf("%d",f[n][n]);//������
    return 0;
}
