#include<iostream>
#include<cstring>
using namespace std;

const int N=100003;

//��������ĩβΪ0������idx��1��ʼ
int h[N],e[N],ne[N],idx=1;//h[]�����ͷ,e[]����ֵ,ne[]������һ��ֵ������

void insert(int x)//����
{
    int k=(x%N+N)%N;//��ϣ�㷨
    
    e[idx]=x,ne[idx]=h[k],h[k]=idx++;
}

bool find(int x)//��ѯ
{
    int k=(x%N+N)%N;//��ϣ�㷨
    
    for(int i=h[k];i!=0;i=ne[i])//��������
        if(e[i]==x)
            return true;//����
    return false;//������
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        char op[2];
        int x;
        
        scanf("%s",&op);
        if(op[0]=='I')
        {
            cin>>x;
            insert(x);
        }
        else
        {
            cin>>x;
            if(find(x))cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}


