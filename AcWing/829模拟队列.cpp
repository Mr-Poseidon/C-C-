#include<iostream>
#include<string>
using namespace std;

const int N=100010;

int q[N],hh=1,tt=0;//q[]�������,hh�����ͷ,tt�����β����ʼ0����

void push(int x)//���
{
    q[++tt]=x;
}

void pop()
{
    hh++;
}

int top()
{
    return q[hh];
}

bool empty()//�ӿ�,����ͷ���ڶ�βʱ��Ϊ�ӿ�
{
    return hh>tt;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        string op;
        
        cin>>op;
        
        if(op=="push")
        {
            cin>>x;
            push(x);
        }
        else if(op=="pop")pop();
        else if(op=="query")cout<<top()<<endl;
        else
        {
            if(empty())cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
