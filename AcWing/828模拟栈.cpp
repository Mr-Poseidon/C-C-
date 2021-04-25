#include<iostream>
#include<string>
using namespace std;

const int N=100010;

int stk[N],tt;//stk[]����ջ,tt����ջ�������Լ�λ��

void push(int x)//��ջ
{
    stk[++tt]=x;
}

void pop()//��ջ
{
    tt--;
}

int top()//ջ��
{
    return stk[tt];
}

bool empty()//�ж�ջ��
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
