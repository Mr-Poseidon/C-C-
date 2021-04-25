#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

char getc(int n)//���ű任
{
    if(n<10)return n+'0';
    else return n-10+'A';
}

string base(int num,int b)//�̳���-����ת��
{
    string ans;
    while(num)
    {
        ans+=getc(num%b);
        num/=b;
    }
    return string(ans.rbegin(),ans.rend());//ע��˴�Ҫ��ת 
}

bool check(string num)//�ж��Ƿ����
{
    for(int i=0,j=num.size()-1;i<j;i++,j--)
        if(num[i]!=num[j])
            return false;
    return true;
}

int main()
{
    int b;
    cin>>b;
    
    for(int i=1;i<=300;i++)//����
    {
        string num=base(i*i,b);//��i^2ת����b������
        if(check(num))//�ж��Ƿ���ġ��ǵĻ����
            cout<<base(i,b)<<" "<<num<<endl;
    }
    return 0;
}
