#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N=12,M=110,K=1<<10;
typedef long long LL;//�������������󡢽�����������Ҫ��LL

LL f[N][M][K];
vector<int> state;//ά�����еĺϷ�״̬
vector<int> head[K];//head[i]ά�����п���ת�Ƶ� i״̬ ���ڽӱ�
int cnt[K];//cnt[i]ά�� i���״̬ ��1�ĸ��������ڷŵĹ���������
int n,m;

/*
    ��������״̬��1��λ�ô�������ڷŵ�λ��
    �ĵã�
        1.����Ϸ���״̬
        2.�ڽӱ���״̬֮���ת�ƹ�ϵ
*/

//�������ڵ�����������״̬�ǲ��Ϸ���
bool check(int state)
{
    for(int i=0;i<n;i++)
        if((state>>i & 1) && (state>>(i+1) & 1))//�жϽ������Ƿ������ڵ�����1
            return false;//�������ڵ�����1
    return true;//������
}

//�����״̬�Ķ�������1�ĸ������������ĸ���
int count(int state)
{
    int ans=0;
    for(int i=0;i<n;i++)ans+=state>>i&1;
    return ans;
}

int main()
{
    cin>>n>>m;
    
    for(int i=0;i<(1<<n);i++)//���˳����еĺϷ�״̬
        if(check(i))
        {
            state.push_back(i);
            cnt[i]=count(i);
        }
            
    
    // ������ĸ��Ϸ���״̬����ת�Ƶ� i���״̬ �������൱�ڼ�֦
    // a&b==0 ��֤��û������1��ͬһ�У�a|b ��֤��û������1��ͬһ��
    for(int i=0;i<state.size();i++)
        for(int j=0;j<state.size();j++)
        {
            int a=state[i],b=state[j];
            
            if(((a&b)==0) && (check(a|b)))
                head[i].push_back(j);
        }
    
    f[0][0][0]=1;//��0�У�һ������Ҳ���ţ���״̬��0 �ǺϷ���һ�ַ���
    
    for(int i=1;i<=n+1;i++)//����ÿһ��
        for(int j=0;j<=m;j++)//�������п��Է��õĹ�������
            for(int a=0;a<state.size();a++)//������������е�״̬a
                for(vector<int>::iterator b=head[a].begin();b!=head[a].end();b++)//�������Ե���״̬a�����кϷ�״̬
                {
                    int c=cnt[state[a]];//�������ǰa���״̬�Ѿ��ڷŵĹ�������
                    
                    if(j>=c)//�����Ҫ�ڷŵ����� ����� �Ѿ��ڷŵ�
                        f[i][j][a]+=f[i-1][j-c][*b];//״̬ת�Ʒ���
                }
                
    cout<<f[n+1][m][0];//���n+1�У��ܹ��ڷ���m�������������һ��û�ڷš���״̬Ϊ0�Ľ��
    return 0;
}


