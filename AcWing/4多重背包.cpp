#include<iostream>
#include<algorithm>
using namespace std;

int n,m,map[105][105];
int vo,va,am;

int main()
{
    cin>>n>>m;
    for(int i=0;i<=m;i++)
        map[0][i]=0;
    
    for(int i=1;i<=n;i++)//��Ʒö�� 
    {
        cin>>vo>>va>>am;
        for(int j=0;j<=m;j++)//�������ö��          
            for(int k=0;k<=am;k++)//�˴�ֱ��ʹ����Ʒ�Ŀ������� 
                if(j>=k*vo)
                    map[i][j]=max(map[i][j],map[i-1][j-k*vo]+k*va);
    }
    cout<<map[n][m]<<endl;
    return 0;
}


/***************************�ָ���*****************************************/ 


#include<iostream>
#include<algorithm>
using namespace std;

const int N=110;

int f[N][N];
int v[N],w[N],s[N];
int n,m;

int main()//��ȫ�����ⷨ
{
    cin>>n>>m;//����
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i]>>s[i];
    
    for(int i=1;i<=n;i++)//������Ʒ
        for(int j=0;j<=m;j++)//������������
            for(int k=0;k<=s[i] && k*v[i]<=j;k++)//������Ʒ����
                f[i][j]=max(f[i][j],f[i-1][j-v[i]*k] + w[i]*k);
    
    cout<<f[n][m]<<endl;
    return 0;
}
