#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=55;

int f[N*2][N][N];//f[k][i][j],kά������,iά��·��һ����,jά��·�߶�����
int w[N][N];//ά��Ȩֵ
int n,m;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>w[i][j];
    
    for(int k=2;k<=n+m;k++)//kͬʱ��������·�ߵĵ�������
        for(int i1=1;i1<=n;i1++)//i1����·��һ����
            for(int i2=1;i2<=n;i2++)//i2����·�߶�����
            {
                int j1=k-i1,j2=k-i2;
                if(1<=j1 && j1<=m && 1<=j2 && j2<=m)
                {
                    
                    int t=w[i1][j1];
                    if(i1!=i2)t+=w[i2][j2];//��ͬ�ĵ���ܴ�����
                    
                    int &x=f[k][i1][i2];
                    x=max(x,f[k-1][i1-1][i2]);//����
                    x=max(x,f[k-1][i1][i2-1]);//����
                    x=max(x,f[k-1][i1-1][i2-1]);//����
                    x=max(x,f[k-1][i1][i2]);//����
                    
                    x+=t;//����Ȩֵ
                }
            }
    
    cout<<f[n+m][n][n];//������
    return 0;
}
