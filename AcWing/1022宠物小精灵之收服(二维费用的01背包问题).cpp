#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010,M=510;

int f[N][M];//f[i][j]ά�� ����������Ϊi������ֵΪjʱ���ɲ�׽�ľ�����������
int n,m,k;

int main()
{
    cin>>n>>m>>k;
    
    while(k--)
    {
        int v1,v2;
        cin>>v1>>v2;//����������ֵ
        
        for(int i=n;i>=v1;i--)//��������������
            for(int j=m-1;j>=v2;j--)//�任˼ά������ֵ���ܵ���0����Ԥ����1������ֵ����m-1��ʼ
                f[i][j]=max(f[i][j],f[i-v1][j-v2]+1);
    }
    
    int c=f[n][m-1],r;//�ɲ�׽�ľ������ֵ f[n][m-1]�е� m-1 Ҳ��Ԥ����1������ֵ
    for(int i=0;i<=m-1;i++)//����Сֵ��ʼ�������ѵ�����ֵ����f[n][i]==cʱ����������ֵ���ѵ���СֵΪi��ʣ�µ�����ֵ��Ϊ���
        if(f[n][i]==c)
        {
            r=i;
            break;
        }
    
    cout<<c<<" "<<m-r;//������ɲ�׽�ľ����������� ʣ������ �����ֵ
    return 0;
}
