#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=410,INF=0x3f3f3f3f;//��������Ҫ��˫���ռ�

int f[N][N],g[N][N];//f[i][j]ά����i�ѵ���j��ʯ�ӵ���Сֵ��g[i][j]ά�����ֵ
int w[N],s[N];//w[i]ά����i��ʯ�ӵ�Ȩֵ��s[i]ά��ǰ׺��
int n;

int main()
{
    cin>>n;//����
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
        w[n+i]=w[i];//�ϻ�����
    }
    
    for(int i=1;i<=2*n;i++)s[i]=s[i-1]+w[i];//ǰ׺��
    
    //��ʼ��
    memset(f,0x3f,sizeof f);
    memset(g,-0x3f,sizeof g);
    
    for(int len=1;len<=n;len++)//ö�ٳ���
        for(int l=1;l+len-1<=n*2;l++)//ö����˵�
        {
            int r=l+len-1;//�Ҷ˵�,ע�⣺�����Ҷ˵��ǿ��Ե������ұߵ��յ��
            
            if(len==1)f[l][r]=g[l][r]=0;//����Ϊ1������Ϊ0
            else//���Ȳ�Ϊ1��ö�ٶϵ�
            {
                for(int k=l;k<r;k++)//ö�ٶϵ�
                {
                    //״̬ת�Ʒ��̣�s[r]-s[l-1]�����κϲ���Ҫ���ѵ�Ȩֵ
                    f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);//ά����Сֵ
                    g[l][r]=max(g[l][r],g[l][k]+g[k+1][r]+s[r]-s[l-1]);//ά�����ֵ
                }
            }
        }
        

    int minv=INF,maxv=-INF;//�����ʼ��
    for(int i=1;i<=n;i++)//ö�����
    {
        minv=min(minv,f[i][i+n-1]);//����Сֵ
        maxv=max(maxv,g[i][i+n-1]);//�����ֵ
    }
    
    cout<<minv<<endl<<maxv;//���
    return 0;
}



