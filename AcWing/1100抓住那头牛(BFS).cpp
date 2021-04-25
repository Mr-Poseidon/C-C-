#include<iostream>
using namespace std;

const int N=2e5+10;

int n,m;
bool vis[N];//ά��ÿ����ķ������
int step[N];//ά��ÿ����Ĳ���
int q[N],hh,tt;//��������

void bfs(int s,int e)//����
{
    hh=tt=0;
    q[tt++]=s;//���
    vis[s]=true;//���
    step[s]=0;//��㲽��Ϊ0
    
    while(hh<tt)
    {
        int p=q[hh++];
        if(p==e)return;
        
        int d[3][2]={1,-1,1,1,2,0};//ά����������
        for(int i=0;i<3;i++)
        {
            int np=p*d[i][0]+d[i][1];//��һ����
            
            if(np<0 || np>2*e)continue;//Խ��
            if(vis[np])continue;//�Ѿ����ʹ�
            
            q[tt++]=np;//���
            vis[np]=true;//���
            step[np]=step[p]+1;//����+1
        }
    }
}

int main()
{
    cin>>n>>m;
    
    if(n>m)cout<<n-m;//���ţ����ǰ��
    else 
    {
        //ţ���˺���
        bfs(n,m);
        cout<<step[m];
    }
    return 0;
}
