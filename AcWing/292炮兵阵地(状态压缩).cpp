#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N=110,M=1<<10;

//ע�⣺����ʹ�ù������飬i&1 �����������������Ϊÿ����������ż����� 

int f[2][M][M];//��������-f[i][a][b]ά���ڷŵ���i�С��ҵ�i��״̬Ϊa����i-1��״̬Ϊb�����԰ڷŵ����ֵ
int w[N];//w[i]ά����i�еĵ��������1����ɽ�ء�0����ƽ��
vector<int> state;//ά�����кϷ�״̬������ͬһ�����ڱ��޷����๥������״̬
int cnt[M];//cnt[i]ά��i���״̬�к��е��ڱ���������1������
int n,m;

//�ж���ͬһ�����Ƿ��ܻ��๥��������-���Ϸ�false������-�Ϸ�true
bool check(int state)
{
    for(int i=0;i<m;i++)
        if((state>>i & 1) && (state>>i+1 & 1 | state>>i+2 & 1))
            return false;
    return true;
}

//�����״̬�е��ڱ�����
int count(int state)
{
    int ans=0;
    for(int i=0;i<m;i++)ans+=state>>i&1;
    return ans;
}

int main()
{
    cin>>n>>m;//����
    for(int i=1;i<=n;i++)
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;
            if(c=='H')
                w[i]+=1<<j;
        }
    
    //ɸѡ���Ϸ�״̬
    for(int i=0;i<(1<<m);i++)
        if(check(i))
        {
            state.push_back(i);
            cnt[i]=count(i);
        }
        
    for(int i=1;i<=n+2;i++)//ö�� ��i�� ���ڱ����
        for(int j=0;j<state.size();j++)//ö�� ��i�� ��״̬
            for(int k=0;k<state.size();k++)//ö�� ��i-1�� ��״̬
                for(int u=0;u<state.size();u++)//ö�� ��i-2�� ��״̬
                {
                    int a=state[j],b=state[k],c=state[u];
                    if((a&b) | (a&c) | (b&c))continue;//����״̬���ܻ��๥����������ܻ��๥����������
                    if((a&w[i]) | (b&w[i-1]) | (c&w[i-2]))continue;//�ڱ����ڷ���ɽ�ص��������������
                    f[i & 1][a][b]=max(f[i & 1][a][b],f[i-1 & 1][b][c]+cnt[a]);//״̬ת�Ʒ���
                }
                
    cout<<f[n+2 & 1][0][0];//����ǰڷŵ���i+2�С���i+1���ڷţ�i+2Ҳ���ڷŵ�ֵ
    return 0;
}

