#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N=55,INF=0x3f3f3f3f;
typedef vector<int> vec;
typedef long long LL;

//������ֵ��󲻳���30λ��9+9+9+3=30�����ó�35λ

vec f[N][N];//f[i][j]ά��i�㵽j�㹹�ɵ�͹����ε����л����������Сֵ
LL w[N];//w[i]ά��i���Ȩֵ
int n;

vec add(vec a,vec b)//�߾���+
{
    vec c;
    for(int i=0,t=0;i<a.size()||i<b.size()||t;i++)
    {
        if(i<a.size())t+=a[i];
        if(i<b.size())t+=b[i];
        c.push_back(t%10);
        t/=10;
    }
    return c;
}

vec mul(vec a,LL b)//�߾���*
{
    vec c;
    LL t=0;
    for(int i=0;i<a.size()||t;i++)
    {
        if(i<a.size())t+=a[i]*b;
        c.push_back(t%10);
        t/=10;
    }
    while(c.size()>1 && c.back()==0)c.pop_back();
    return c;
}

int cmp(vec a,vec b)//�߾��ȱȽϴ�С
{
    if(a.size()>b.size())return 1;
    else if(a.size()<b.size())return -1;
    
    for(int i=a.size()-1;i>=0;i--)
        if(a[i]>b[i])return 1;
        else if(a[i]<b[i])return -1;
    
    return 0;
}

void print(vec a)//�߾������
{
    for(int i=a.size()-1;i>=0;i--)cout<<a[i];
    return;
}

int main()
{
    cin>>n;//����
    for(int i=1;i<=n;i++)cin>>w[i];
    
    for(int i=0;i<=n;i++)//�߾��ȳ�ʼ����0
        for(int j=0;j<=n;j++)
            f[i][j]=vec(1,0);
    
    for(int len=3;len<=n;len++)//ö�ٳ��ȡ�͹�����������һ�������Ρ��������㹹��
        for(int l=1;l+len-1<=n;l++)//ö�ٶ���ε����
        {
            int r=l+len-1;//����ε��յ�
            f[l][r]=vec(35,9);//�߾��ȳ�ʼ�������ֵ����ÿһλ����9
            
            for(int k=l+1;k<r;k++)//ö��ÿһ�����Ի��ֵĵ�
            {
                //f[l][r]=min(f[l][r],f[l][k]+f[k][r]+w[l]*w[k]*w[r]);//����ֵ��״̬ת�Ʒ���
                
                //����״̬ת�Ʒ���
                vec t(1,1);//���˷�����ʼ����1
                t=mul(t,w[l]);
                t=mul(t,w[k]);
                t=mul(t,w[r]);
                t=add(t,f[l][k]);
                t=add(t,f[k][r]);
                
                if(cmp(f[l][r],t)==1)//���f[l][r]>t
                    f[l][r]=t;//ȡ��Сֵ
            }
        }
    print(f[1][n]);//������
    return 0;
}

