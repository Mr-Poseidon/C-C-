#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=100010,M=110,INF=0x3f3f3f3f;

//f[i][j][0]-ǰi�죬�Ѿ�������j�ν��ף��������� û�й�Ʊ
//f[i][j][1]-ǰi�죬�Ѿ�������j�ν��ף��������� �й�Ʊ
int f[N][M][2];
int w[N];
int n,m;

//����:�����ʱ�����һ�ν���

int main()
{
    cin>>n>>m;//����
    for(int i=1;i<=n;i++)cin>>w[i];
    
    //��ʼ��
    memset(f,-0x3f,sizeof f);
    for(int i=0;i<=n;i++)f[i][0][0]=0;//ǰi���У�����0�ν��ף�������û�й�Ʊ�ǺϷ���
    
    for(int i=1;i<=n;i++)//��������
        for(int j=1;j<=m;j++)//�������״���
        {
            //״̬ת�Ʒ���
            f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1]+w[i]);//����������
            f[i][j][1]=max(f[i-1][j][1],f[i-1][j-1][0]-w[i]);//��������
        }

        
    //������m�ν��ס�����������m�ν��׵�ʱ��������ֵ
    int ans=0;
    for(int i=0;i<=m;i++)ans=max(ans,f[n][i][0]);//ǰn���У�������i�ν��ס�������û�й�Ʊ
    
    cout<<ans;//������
    
    return 0;
    
}
