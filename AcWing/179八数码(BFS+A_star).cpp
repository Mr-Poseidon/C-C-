#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<queue>
#include<cmath>
using namespace std;

typedef pair<int,string> PIS;
#define x first
#define y second

//�ڰ��������ʮ�������У�ֻ������Ե�������ż��ʱ�����н�
//BFS+IDA*�㷨��һ�������������Σ�����dijistra�㷨�������յ�ֻ�ڵ�һ�γ��ӵ�ʱ��������

string a,b;//a���ʼ��״̬��b��û��x��״̬�������������
unordered_map<string,int> dis;//ά��ÿ��״̬�ľ���
unordered_map<string,string> path;//ά��ÿ��״̬���ж���¼
priority_queue<PIS,vector<PIS>,greater<PIS>> q;//ά������ʵ����+��ֵ���룩�����ȶ���

char moves[4]={'u','l','r','d'};//�����ĸ������ϵ��ĸ�״̬
int d[4][2]={-1,0,0,-1,0,1,1,0};//��Ӧ���ĸ�����-��������


int f(string s)//��ֵ����-��ÿ��״̬��ÿ����ֵ��������·��
{
    int ans=0;
    for(int i=0;i<s.size();i++)
        if(s[i]!='x')//��x������
        {
            int t=s[i]-'1';//�����ȷ��λ��
            ans+=abs(i/3 - t/3)+abs(i%3 - t%3);//���ֵ����ȷλ�õ�������·����ֵ
        }
    return ans;//���ظ�״̬��Ӧ��������·��ֵ���ܺ�
}

void bfs(string state)//����
{
    dis[state]=0;//������Ϊ0
    path[state]="";//����ж���¼Ϊ��
    q.push({0+f(state),state});//���
    
    while(q.size())
    {
        PIS p=q.top();
        q.pop();
        
        state=p.y;//ȡ״̬
        if(state=="12345678x")return;//�����յ㡢����
        
        int xs;
        for(int i=0;i<9;i++)//�����״̬��x���ڵ�λ��
            if(state[i]=='x')
            {
                xs=i;
                break;
            }
        
        for(int i=0;i<4;i++)//�����ĸ�����
        {
            // xs/3 ������, xs%3 ������ 
            int nx=xs/3+d[i][0],ny=xs%3+d[i][1];//������һ�����������
            if(nx<0 || nx>=3 || ny<0 || ny>=3)continue;//Խ��
            
            int nxs=nx*3+ny;//�����һ����������Ӧ��λ��
            
            swap(state[xs],state[nxs]);//��������չ����һ��״̬
            if(dis.count(state)==0 || dis[state]+1>dis[p.y])//��״̬������ ���� ��״̬���Ը��� 
            {
                dis[state]=dis[p.y]+1;//����+1
                path[state]=path[p.y]+moves[i];//�����ж���¼
                q.push({dis[state]+f(state),state});//���
            }
            swap(state[xs],state[nxs]);//�ָ�״̬
        }
    }
    return;
}
int main()
{
    for(int i=0;i<9;i++)//����
    {
        char t;
        cin>>t;
        a+=t;
        if(t!='x')b+=t;
    }
    
    int cnt=0;
    for(int i=0;i<8;i++)//����ʼ״̬����������
        for(int j=i+1;j<8;j++)
            if(b[i]>b[j])
                cnt++;
    
    if(cnt%2!=0)cout<<"unsolvable"<<endl;//��������Ϊ�������޽�
    else//��������Ϊż�������Ѳ�����ж�·��
    {
        bfs(a);
        cout<<path["12345678x"]<<endl;
    }
    
    return 0;
}
