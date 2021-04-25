#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N=15,M=12,mod=1e8;

int f[N][1<<M];//f[i][a]ά��ǰi��״̬Ϊa�ķ�����
int w[N];//w[i]ά����i�еķǷ�״̬��1����Ƿ��������֣�0����Ϸ������֣�
vector<int> state;//ά�����кϷ�״̬
vector<int> head[1<<M];//�ڽӱ�ά��״̬֮���ת�ƹ�ϵ
int n,m;

//ע�⣺ == �����ȼ����� & �������õ� & �ĵط���Ҫ�ӣ��� 
 
//�жϸ�״̬�Ƿ����������ڵ�1
bool check(int state)
{
    for(int i=0;i<m;i++)
        if((state>>i & 1) && (state>>(i+1) & 1))
            return false;
    return true;
}

int main()
{
    cin>>n>>m;//����
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)//��¼���зǷ�����
        {
            int t;
            cin>>t;
            w[i]<<=1;
            w[i]+=t;
        }
        w[i]=~w[i];//����¼ȡ������1����Ƿ���0����Ϸ�������ֲ
    }
    
    //ɸѡ�����кϷ�״̬
    for(int i=0;i<(1<<m);i++)
        if(check(i))
            state.push_back(i);
    
    //ɸѡ��ÿһ��״̬���Դ��ĸ���һ��״̬�Ϸ�ת�ƹ���
    for(int i=0;i<state.size();i++)//����ÿ��״̬a
        for(int j=0;j<state.size();j++)//����ÿ��״̬b
            if((state[i]&state[j])==0)//�ж�״̬b�Ƿ���ת�Ƶ�a
                head[i].push_back(j);//�ǵĻ���¼״̬�±�
    
    f[0][0]=1;//�ʼ��һ��ʲô�������ǺϷ���һ�ַ���
    for(int i=1;i<=n+1;i++)//����ÿһ��
        for(int a=0;a<state.size();a++)//��������״̬
            if((state[a]&w[i])==0)//�жϸ�״̬�Ƿ��ͻ���������˷Ƿ��������֣���������
                for(vector<int>::iterator b=head[a].begin();b!=head[a].end();b++)//*b������ǿ��ԺϷ�ת�Ƶ�״̬state[a]���±�
                    f[i][state[a]]=(f[i][state[a]]+f[i-1][state[*b]])%mod;//״̬ת�Ʒ���
    
    cout<<f[n+1][0];//������п��еķ��������ֵ�n+1�С���n+1��ʲô�����ֵķ���
    return 0;
}
