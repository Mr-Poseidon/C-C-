#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=310;

int s[N];//ά��ǰ׺��
int f[N][N];//ά��������С����
int n;

int main()
{
    memset(f,0x3f,sizeof f);//����Сֵ����ʼ��Ϊ���ֵ
    
    cin>>n;//����
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        s[i]+=s[i-1];//����ǰ׺��
        f[i][i]=0;//�������Ϊ0
    }
    
    for(int len=2;len<=n;len++)//�������䳤��
        for(int i=1;i+len-1<=n;i++)//�����������
        {
            int j=i+len-1;//�����յ�
            for(int k=i;k<j;k++)//ö������ϵ�
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
        }
            
    
    cout<<f[1][n];//���1-n����������С����
    return 0;
}
