#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1010,M=N*N;
typedef pair<int,int> PII;
#define x first
#define y second

int g[N][N];//ά����ͼ
bool vis[N][N];//ά���������
int n;

PII q[M];//ά����������
int hh,tt;

void bfs(int sx,int sy,bool& isp,bool& isv)//���ѣ�isp������ɽ�壬isv������ɽ��
{
    hh=tt=0;
    q[tt++]={sx,sy};//������
    vis[sx][sy]=true;//���
    
    while(hh<tt)
    {
        PII p=q[hh++];
        
        for(int i=p.x-1;i<=p.x+1;i++)//�����˸�����
            for(int j=p.y-1;j<=p.y+1;j++)
            {
                if(i==p.x && j==p.y)continue;//��������
                if(i<0 || i>=n || j<0 || j>=n)continue;//Խ�硢����
                
                if(g[i][j]==g[sx][sy] && !vis[i][j])//���ڱ�����û�з��ʹ������
                {
                    q[tt++]={i,j};
                    vis[i][j]=true;
                }
                else if(g[i][j]!=g[sx][sy])//�����ڱ����϶����ܱ�
                {
                    if(g[i][j]<g[sx][sy])isv=false;//�ܱ�С�ڱ�������Ϳ϶�����ɽ��
                    else isp=false;//�ܱߴ��ڱ�������϶�����ɽ��
                }
            }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)//����
        for(int j=0;j<n;j++)
            cin>>g[i][j];
    
    int peak=0,valley=0;//ά��ɽ�塢ɽ�ȵ�����
    for(int i=0;i<n;i++)//����ÿһ����
        for(int j=0;j<n;j++)
            if(!vis[i][j])//δ���ʹ�
            {
                bool isp=true,isv=true;
                bfs(i,j,isp,isv);//�˴�ɽ���ɽ�ȵ�boolֵ�����ǵ�ַ
                if(isp)peak++;//�����ɽ��
                if(isv)valley++;//�����ɽ��
            }
    
    cout<<peak<<" "<<valley;//���
    return 0;
}

