#include<iostream>
#include<cstring>
using namespace std;

const int N=10003,null=0x3f3f3f3f;
int h[N];

int n,m;

int find(int x)//ֻ�����������Ķ���̽�ⷨ
{
    for(int i=0;i<m;i++)
    {
        int k=(x%m+i*i)%m;//��������ָ ֻ����i^2 
        if(h[k]==null || h[k]==x)
            return k;
    }
    return -1;//�����ڻ����޷�����
}

int main()
{
    memset(h,0x3f,sizeof(h));//ɢ�б��ʼ��
    
    cin>>m>>n;
    //��ȡ����ɢ�б��С����С����
    for(int i=m;;i++)
    {
        bool f=true;
        for(int j=2;j*j<=i;j++)
            if(i%j==0)
            {
                f=false;
                break;
            }
        if(f)
        {
            m=i;//������ֵ
            break;
        }
    }
    
    int x;
    while(n--)
    {
        cin>>x;
        int k=find(x);//��ϣ
        if(k!=-1)//�Ƿ����
        {
            cout<<k<<' ';
            h[k]=x;
        }
        else cout<<"- ";
    }
    return 0;  
}
