#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010;

int g[N][N];//��ų�ʼ����
int gmax[N][N],gmin[N][N];//gmaxά�����ֵ�ľ���gminά����Сֵ�ľ���
int n,m,k;
int q[N],hh,tt;//ά����������


void get_max(int a[],int b[],int tot)//ά�����ֵ�ĵ�������
{
    hh=tt=0;
    for(int i=1;i<=tot;i++)
    {
        if(hh<tt && q[hh]<=i-k)hh++;
        while(hh<tt && a[q[tt-1]]<a[i])tt--;
        q[tt++]=i;
        b[i]=a[q[hh]];
    }
}

void get_min(int a[],int b[],int tot)//ά����Сֵ�ĵ�������
{
    hh=tt=0;
    for(int i=1;i<=tot;i++)
    {
        if(hh<tt && q[hh]<=i-k)hh++;
        while(hh<tt && a[q[tt-1]]>a[i])tt--;
        q[tt++]=i;
        b[i]=a[q[hh]];
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);//����
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&g[i][j]);
            
    for(int i=1;i<=n;i++)//����ÿһ��
    {
        get_min(g[i],gmin[i],m);//ά��ÿһ�е���Сֵ
        get_max(g[i],gmax[i],m);//ά��ÿһ�е����ֵ
    }
    
    int ans=0x3f3f3f3f;//��ʼ����
    int a[N],b[N],c[N];//a���������ʱ���У�b�������е���Сֵ��c�����������ֵ
    for(int i=k;i<=m;i++)//�����У���k�п�ʼ
    {
        for(int j=1;j<=n;j++)a[j]=gmin[j][i];//�д�����ʱ����
        get_min(a,b,n);//ά���е���Сֵ
        
        for(int j=1;j<=n;j++)a[j]=gmax[j][i];//�д�����ʱ����
        get_max(a,c,n);//ά���е����ֵ
        
        for(int j=k;j<=n;j++)ans=min(ans,c[j]-b[j]);//��k��ʼ��ά����С�Ĳ�ֵ
    }
    
    printf("%d\n",ans);//������
    return 0;
}
