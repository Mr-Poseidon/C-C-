#include<iostream>
#include<algorithm>
using namespace std;

const int N=310;

//�ṹ��ά������
struct P{
    int id;
    int a,b,c;
    int sum;
    
    //����<
    bool operator<(const P& p)const
    {
        if(sum!=p.sum)return sum>p.sum;
        if(a!=p.a)return a>p.a;
        return id<p.id;
    }
    
}p[N];

int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)//����
    {
        p[i].id=i;
        cin>>p[i].a>>p[i].b>>p[i].c;
        p[i].sum=p[i].a+p[i].b+p[i].c;
    }
    
    sort(p+1,p+n+1);//����
    
    //������
    for(int i=1;i<=5;i++)
        cout<<p[i].id<<" "<<p[i].sum<<endl;
    
    return 0;
}
