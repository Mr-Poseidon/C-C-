#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=20,M=1<<N;

int w[N][N];//ά���㵽���Ȩֵ
int f[M][N];//f[i][j]ά�� i ���״̬�У����������ߵ� j ���������·��
int n;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)//����Ȩֵͼ
        for(int j=0;j<n;j++)
            cin>>w[i][j];
    
    memset(f,0x3f,sizeof f);//����Сֵ����ʼ�����ֵ
    f[1][0]=0;//1����0������Ѿ��߹���0�ߵ�0ȨֵΪ0��0Ϊ���
    
    for(int i=0;i<1<<n;i++)//��������״̬
        for(int j=0;j<n;j++)//�������״̬�п�����Ϊ�յ�ĵ�
            if(i>>j&1)//����������ڣ�����Ϊ�յ�
                for(int k=0;k<n;k++)//�������п��ܵ���һ����
                //  if((i>>k&1)&&(j!=k)) �����˴�Ҳ��д������ 
                    if((i-(1<<j))>>k&1)//�ȿ�ȥ����ĵ㣬��������ת�ƣ����������һ�����ת��
                        // i-(1<<j)�۵��յ��ֵ��Ϊ��һ�����״̬,kΪ��һ����Ķ�����λ��
                        f[i][j]=min(f[i][j],f[i-(1<<j)][k]+w[k][j]);
    
    // (1<<n)-1 ��ʾ���е㶼�߹���״̬��n-1�����յ�ĵ�
    cout<<f[(1<<n)-1][n-1];
    return 0;
}
