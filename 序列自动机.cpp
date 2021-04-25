#include<iostream>
#include<string>
using namespace std;

const int INF=1e5+7;
int nxt[100000][27];//代表从i开始,j字母最早出现的位置 


void init(string s)//初始化自动机 
{
	int len=s.size();
	
	for(int i=0;i<26;i++)nxt[len][i]=INF;
	for(int i=len-1;i>=0;i--)
	{
		for(int j=0;j<26;j++)
			nxt[i][j]=nxt[i+1][j];//向后继承 
		nxt[i][s[i]-'a']=i;//更新 
	}
}

bool find(string s)//查找子序列 
{
	int p=-1;//p指针初始化为-1 
	int len=s.size();
	
	for(int i=0;i<len;i++)
	{
		p=nxt[p+1][s[i]-'a'];//自动机自动后移 
		if(p==INF)return false;
	}
	return true;
} 



int main()
{
	return 0;
}
