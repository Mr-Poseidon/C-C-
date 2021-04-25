#include<iostream>
#include<algorithm>
using namespace std;

const int N=11,M=16;

int w[N][M];//ά��ÿ����Ʒ�ļ�ֵ 
int f[N][M];//ά�����Ž⡢�󷽰������Ż�����һά 
int way[N];//��¼ÿ��ѡ�����Ʒ��� 
int n,m;//n-��Ʒ������m-������� 

//ע�⣺������Ʒ��������豸�������� ��Ʒ����ţ��ڼ�����Ʒ��

int main()
{
    cin>>n>>m;//����
    for(int i=1;i<=n;i++)//������Ʒ����
        for(int j=1;j<=m;j++)//����������Ʒ�ļ�ֵ
            cin>>w[i][j];
    
    for(int i=1;i<=n;i++)//������Ʒ����
        for(int j=m;j>=0;j--)//�����������
        {
            f[i][j]=f[i-1][j];//��ѡ
            for(int k=1;k<=j;k++)//�����ж�ѡ�ĸ���Ʒ
                f[i][j]=max(f[i][j],f[i-1][j-k]+w[i][k]);
        }
    
    cout<<f[n][m]<<endl;//������Ž�
    
    //�������
    int j=m;//������
    for(int i=n;i>0;i--)//�Ӻ���ǰ������Ʒ��
        for(int k=1;k<=j;k++)//����ÿ���е�ÿ����Ʒ
            if(f[i][j]==f[i-1][j-k]+w[i][k])//�ж��Ƿ�̳�
            {
                way[i]=k;//��¼ѡ�����Ʒ
                j-=k;//�۵������������Ʒ��ż�Ϊ���
                break;
            }
            
    for(int i=1;i<=n;i++)//�������
        cout<<i<<" "<<way[i]<<endl;
    
    return 0;
}
