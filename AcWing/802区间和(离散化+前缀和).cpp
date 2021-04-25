#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//��Ϊ��ӻ����1e5�����꣬��ѯ�����2e5�����꣬�ܹ�3e5��
const int N=300010;
//a[N]������ԭʼ���飬s[N]ά��ǰ׺��
int a[N],s[N];

int n,m;
//add����Ӳ�����query���ѯ����
vector<pair<int,int>> add,query;
//allsά��������ɢ��
vector<int> alls;


int find(int x)//������ɢ���������
{
    //��Ϊά������ͣ���������+1
    return lower_bound(alls.begin(),alls.end(),x)-alls.begin()+1;
}
int main()
{
    cin>>n>>m;//����
    for(int i=0;i<n;i++)
    {
        int x,c;
        cin>>x>>c;
        add.push_back({x,c});//����Ӳ���
        
        alls.push_back(x);//������
    }
    
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        query.push_back({a,b});//���ѯ����
        
        //������
        alls.push_back(a);
        alls.push_back(b);
    }
    
    sort(alls.begin(),alls.end());//����
    alls.erase(unique(alls.begin(),alls.end()),alls.end());//ȥ��
    
    for(vector<pair<int,int>>::iterator it=add.begin();it!=add.end();it++)//��Ӳ���
    {
        int p=find((*it).first);
        a[p]+=(*it).second;
    }
    
    //ά��ǰ׺��
    int si=alls.size();
    for(int i=1;i <= si;i++) s[i]=s[i-1]+a[i];
    
    for(vector<pair<int,int>>::iterator it=query.begin();it!=query.end();it++)//��ѯ����
    {
        int a=find((*it).first),b=find((*it).second);
        cout<<s[b]-s[a-1]<<endl;
    }
    return 0;
}
