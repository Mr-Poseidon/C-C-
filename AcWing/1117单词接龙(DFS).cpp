#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const int N=25;

string word[N];//word[i]维护第i个单词
int f[N][N];//f[i][j]维护第j个单词接在第i个单词的后面、最短重合部分的长度
int cnt[N];//cnt[i]维护第i个单词的使用次数
int n,ans;
char ch;

void dfs(string s,int k)//深搜
{
    ans=max((int)s.size(),ans);//更新新的长度
    
    cnt[k]++;//第k个单词使用次数+1
    
    for(int i=0;i<n;i++)//遍历每一个单词
        if(f[k][i] && cnt[i]<2)//第i个单词可以接在第k个单词的后面、且使用次数少于2次
            dfs(s+word[i].substr(f[k][i]),i);//原本的字符串s + 第i个单词和第k个单词不重合的部分，使用的是第i个单词
    
    cnt[k]--;//第k个单词使用次数-1
}
int main()
{
    cin>>n;//输入
    for(int i=0;i<n;i++)cin>>word[i];
    cin>>ch;
    
    for(int i=0;i<n;i++)//遍历每一个单词、判断第j个单词接在第i个单词后面、重合部分的最小长度是多少
        for(int j=0;j<n;j++)
        {
            string a=word[i],b=word[j];
            for(int k=1;k<(int)min(a.size(),b.size());k++)//从1开始遍历
                if(a.substr(a.size()-k,k)==b.substr(0,k))//存在即为最小长度
                {
                    f[i][j]=k;//记录
                    break;//结束循环
                }
                    
        }
        
    for(int i=0;i<n;i++)//遍历每一个单词
        if(word[i][0]==ch)//若单词的首字母是龙头、开始深搜
            dfs(word[i],i);
    
    cout<<ans;//输出结果
    return 0;
}
