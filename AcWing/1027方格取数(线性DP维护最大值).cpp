#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=15;

//��������ͬʱ�ߡ���ô���ǵĲ���һ����ȡ�����λ�ò�һ�����

int w[N][N];//w[i][j]ά���㣨i��j������ֵ
int f[N*2][N][N];//f[k][i1][i2]ά��k������һ�����ߵĺ������i1���ڶ������ߵĺ������i2��������뼴Ϊk-i1��k-i2�����ֵ
int n,a,b,c;

int main()
{
    scanf("%d",&n);//��������
    
    while(scanf("%d%d%d",&a,&b,&c),a||b||c)w[a][b]=c;//�������ֵ
    
    for(int k=2;k<=n+n;k++)//��������
        for(int i1=1;i1<=n;i1++)
            for(int i2=1;i2<=n;i2++)
            {
                int j1=k-i1,j2=k-i2;//�ó���������������
                if(j1>=1 && j1<=n && j2>=1 && j2<=n)//���ںϷ���Χ��
                {
                    int t=w[i1][j1];
                    if(i1!=i2)t+=w[i2][j2];//��λ�ò���ͬ��������ֵ�����ϡ���λ����ͬ��һ��ֵֻ��ȡһ��
                    
                    //ѡ��ת�Ƶ����ֵ
                    int &x=f[k][i1][i2];
                    x=max(x,f[k-1][i1-1][i2]);//���ҡ�����
                    x=max(x,f[k-1][i1][i2-1]);//���¡�����
                    x=max(x,f[k-1][i1-1][i2-1]);//���ҡ�����
                    x=max(x,f[k-1][i1][i2]);//���¡�����
                    
                    x+=t;//���ϸõ����ֵ
                }
            }
            
    printf("%d",f[n<<1][n][n]);//������
    return 0;
        
}
