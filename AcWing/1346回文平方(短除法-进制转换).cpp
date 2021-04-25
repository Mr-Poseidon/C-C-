#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

char getc(int n)//符号变换
{
    if(n<10)return n+'0';
    else return n-10+'A';
}

string base(int num,int b)//短除法-进制转换
{
    string ans;
    while(num)
    {
        ans+=getc(num%b);
        num/=b;
    }
    return string(ans.rbegin(),ans.rend());//注意此处要翻转 
}

bool check(string num)//判断是否回文
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
    
    for(int i=1;i<=300;i++)//遍历
    {
        string num=base(i*i,b);//将i^2转换成b进制数
        if(check(num))//判断是否回文、是的话输出
            cout<<base(i,b)<<" "<<num<<endl;
    }
    return 0;
}
