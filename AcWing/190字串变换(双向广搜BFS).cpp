#include<iostream>
#include<algorithm>
#include<cstring>
#include<unordered_map>
#include<queue>
using namespace std;

const int N=6;

string A,B;
string a[N],b[N];
int n=0;

//���ڱ��������˵����չ��ʽ��˳��ǰ��֮�֡�����Ҫ�ֱ�ά�������˵�ĸ��ԵĶ���״̬������дһ����չ����

unordered_map<string,int> da,db;//ά��a��b������Ԫ�صľ���
queue<string> qa,qb;//ά��a��b����

//��չ��q����Ҫ�����Ķ��У�da��db��������������Ԫ�صľ��룬a״̬ ת���� b״̬
int extend(queue<string>& q,unordered_map<string,int>& da,unordered_map<string,int>& db,string a[],string b[])
{
    string ts=q.front();//ȡ����ͷ
    q.pop();
    
    for(int i=0;i<n;i++)//�����任����
        for(int j=0;j<(int)ts.size();j++)//�������
            if(ts.substr(j,(int)a[i].size())==a[i])//���Խ��б任
            {
                string nst=ts.substr(0,j)+b[i]+ts.substr(j+a[i].size());//��ȡ�µ�״̬
                
                if(db.count(nst))return da[ts]+db[nst]+1;//��״̬��������һ�������У����ز���
                
                if(da.count(nst))continue;//����״̬�ڱ������г��ֹ�������
                q.push(nst);//���
                da[nst]=da[ts]+1;//����+1
            }
    return 11;//����11����ʾ�޷�����
}
int bfs()
{
    //������ͷ��� �� ��ǲ���Ϊ0
    qa.push(A),da[A]=0;
    qb.push(B),db[B]=0;
    
    //ֻ���������ж����ڲ��п��ܵ��������һ������û���ѵ����Ҷ���Ϊ�ա�˵����������Ǹ��ջ�
    while(qa.size() && qb.size())
    {
        int step=0;
        if(qa.size()<=qb.size())step=extend(qa,da,db,a,b);//�Ż�����˳�򡢴�������ٵĶ��п�ʼ��չ
        else step=extend(qb,db,da,b,a);
        
        if(step<=10)return step;//������̾���
    }
    return 11;
}


int main()
{
    cin>>A>>B;//����
    while(cin>>a[n]>>b[n])n++;
    
    int step=bfs();//˫�����
    
    if(step<=10)cout<<step<<endl;//���
    else puts("NO ANSWER!");
    
    return 0;
}
