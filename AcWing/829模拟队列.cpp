#include<iostream>
#include<string>
using namespace std;

const int N=100010;

int q[N],hh=1,tt=0;//q[]代表队列,hh代表队头,tt代表队尾，初始0弃置

void push(int x)//入队
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

bool empty()//队空,当队头大于队尾时即为队空
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
