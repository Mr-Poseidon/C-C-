/*
�����ҵ��������ڣ��򷵻ص������������Զ�ָ����ڲ���������Сֵ 
����������
6 3
1 2 2 3 3 4
3
4
5
���������
3 4
5 5
-1 -1
*/ 

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,q,a[100005];

int main()
{
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> b(a,a+n);
    pair<vector<int>::iterator,vector<int>::iterator> p;
    while(q--)
    {
        int t;
        cin>>t; 
        p=equal_range(b.begin(),b.end(),t);
        if(*p.first!=t)cout<<"-1 -1"<<endl;
        else cout<<p.first-b.begin()<<" "<<p.second-b.begin()-1<<endl;
        
    }
    return 0;
}
