#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=20;

int n;
int q[N];//�����ʱ������
int w[5][N];//ά��ÿһ���ʼ������

//q[i]+1=a[i+1] ˵��q[i]�ĺ���ǺϷ���

int f()//��ֵ����
{
    int cnt=0;//ά�����Ϸ��ĺ�̸���
    for(int i=0;i+1<n;i++)
        if(q[i]+1!=q[i+1])
            cnt++;
    return (cnt+2)/3;//��Ϊÿ���ƶ�����޸�������̣��������ٶ�����Ҫ���� ( cnt+2 )/3 ��
}

bool dfs(int u,int depth)//�����������
{
    if(u+f()>depth)return false;//���εĲ�����������Ԥ�������ٵĲ��������������ƵĲ�����ֱ�ӷ���false
    if(f()==0)return true;//���к�̶��ǺϷ���
    
    for(int len=1;len<=n;len++)//�����������еĳ���
        for(int l=0;l+len-1<n;l++)//�������
        {
            int r=l+len-1;//������յ�
            
            for(int k=r+1;k<n;k++)//���������λ��
            {
                memcpy(w[u],q,sizeof(q));//��¼ԭ��������
                
                //ȡ��������һ�β����룬q��ŵ����µ�����
                int x=l;
                for(int y=r+1;y<=k;y++,x++)q[x]=w[u][y];
                for(int y=l;y<=r;y++,x++)q[x]=w[u][y];
                if(dfs(u+1,depth))return true;
                
                memcpy(q,w[u],sizeof(w[u]));//�ָ�ԭ��������
            }
        }
    return false;//����ʧ��
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;//����
        for(int i=0;i<n;i++)cin>>q[i];
        
        int depth=0;//��������Ĳ���
        while(depth<5)//��5������
        {
            if(dfs(0,depth))break;//���Ե����break
            depth++;
        }
        
        //������
        if(depth<5)cout<<depth<<endl;
        else puts("5 or more");
    }
    return 0;
}
