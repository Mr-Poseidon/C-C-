#include<iostream>
#include<algorithm>
using namespace std;

int n,m,map[1005][1005];
int t,v;

int main()//������ȫ���� 
{
    cin>>n>>m;
    for(int i=0;i<=m;i++)
        map[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>t>>v;//��������ͼ�ֵ 
        for(int j=0;j<=m;j++)
        {
            int acount=j/t;//������Ʒ�ɷ��õ�������� 
            map[i][j]=map[i-1][j];//���� 
            for(int k=1;k<=acount;k++)
                if(j>=k*t)//˼�����˴����ж��Ƿ��ȥ�������� 
                    map[i][j]=max(map[i][j],map[i-1][j-k*t]+k*v);//ע��˴���̬ת�� 
        }
    }
    cout<<map[n][m]<<endl;
    return 0;
}

/************************************�ָ���******************************************/                             
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1005;

int f[N];//�Ż���һά
int v[N],w[N];//ά����Ʒ������ͼ�ֵ
int n,m;//n����Ʒ��m���ռ�

int main()//����ȫ������ѭ���Ż��� 
{
    cin>>n>>m;//����
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
    
    for(int i=1;i<=n;i++)
        for(int j=v[i];j<=m;j++)//������ȫ������ʽ���Ƴ�ÿ�����ݸ��¶���Ҫ�õ�ǰ���ֵ�����Դ�ǰ�������
            f[j]=max(f[j],f[j-v[i]]+w[i]);//״̬ת�Ʒ���
    
    cout<<f[m]<<endl;
    return 0;
}
