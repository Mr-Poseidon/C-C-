#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=110;

int n;
int path[N];//ά��������ܵ����� 

bool dfs(int u,int depth)//������������
{
    if(path[u-1]==n)return true;//ǰһ������������Ҫ�Ľ��
    if(u==depth)return false;//��Խָ�����
    
    bool use[N]={false};//���ڼ�¼�ù������������ظ�����
    
    //ö��ÿ�����ܵ���
    for(int i=u-1;i>=0;i--)//�Ż�����˳�������������ֵ�����ԴӺ���ǰö��
        for(int j=i;j>=0;j--)
        {
            int v=path[i]+path[j];
            if(v>n || v<path[u-1] || use[v])continue;//Խ�硢�����ù�������
            
            use[v]=true;//���
            path[u]=v;//��¼
            if(dfs(u+1,depth))return true;//��������
        }
    return false;
}
int main()
{
    
    while(cin>>n && n)//�����������
    {
        path[0]=1;//��һ����Ϊ1
        int depth=1;//���Ϊ1
        
        while(!dfs(1,depth))depth++;//������������
        
        for(int i=0;i<depth;i++)cout<<path[i]<<" ";//���
        cout<<endl;
    }
    return 0;
}
