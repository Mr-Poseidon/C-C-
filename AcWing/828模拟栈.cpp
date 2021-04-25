#include<iostream>
#include<string>
using namespace std;

const int N=100010;

int stk[N],tt;//stk[]代表栈,tt代表栈的数量以及位置

void push(int x)//入栈
{
    stk[++tt]=x;
}

void pop()//出栈
{
    tt--;
}

int top()//栈顶
{
    return stk[tt];
}

bool empty()//判断栈空
{
    return tt==0;
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
        else if(op=="empty")
        {
            if(empty())cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else 
        {
            cout<<top()<<endl;
        }
    }
    return 0;
}
