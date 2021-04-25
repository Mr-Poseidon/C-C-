#include<iostream>
#include<cstdio>
#include<string>
#include<bitset>
#include<cstdlib>
using namespace std;

typedef long long int ll;

string getbit(ll num)//得到二进制字符串 
{
	bitset<4> b(num);
	return b.to_string();
}
int is_ans(string s)
{
	string t=s+"0";//方便处理尾部 
	int ans=0;
	for(int i=1;i<s.size();i++)
	{
		if(t[i-1]=='1')
		{
			ans++;//翻转次数++ 
			
			t[i-1]='0';
			
			if(t[i]=='1')t[i]='0';
			else t[i]='1';
			
			if(t[i+1]=='1')t[i+1]='0';
			else t[i+1]='1';
		}
	}
	if(t[s.size()-1]=='1')return -1;//无解 
	else return ans;//有解 
}
int main()
{
	string ss,bs;
	/* 
	//法一 ： 时间超限6% 
	cin>>ss;
	for(int i=0;i<ss.size();i++)//转化为二进制串 
	{
		int num;
		// &(ss.c_str()[i] - 字符串第i位开始的子字符串
		//只输入1位可以避免字符串最后位数不够出现前导0的问题 
		sscanf(&(ss.c_str()[i]),"%1X",&num);//以16进制的形式输入1位 
		bs+=getbit(num);
	}
	*/ 
 
	//法二 
	ll num;
	while(~scanf("%1X",&num))
		bs+=getbit(num);
	
	//cout<<bs<<endl;
	
	while(bs[0]=='0')//删除前导0 
		bs.erase(0,1);
	
	if(bs.size()==0 || bs.size()==1)//特殊情况 
	{
		cout<<bs.size();
		return 0;
	}
		
	int ans1=is_ans(bs);//前转3
	
	if(bs[0]=='1')bs[0]='0';//翻转前两位 
	else bs[0]='1';
	if(bs[1]=='1')bs[1]='0';
	else bs[1]='1';
	
	int ans2=is_ans(bs);//前转2 
	if(ans2!=-1)ans2++;//如果有解，就加上翻转前两位的一次 
	
	if(ans1==-1 && ans2==-1)cout<<"No";//输出结果 
	if(ans1!=-1 && ans2==-1)cout<<ans1;
	if(ans1==-1 && ans2!=-1)cout<<ans2;
	if(ans1!=-1 && ans2!=-1)cout<<min(ans1,ans2);//都有解输出最小的结果 
	
	return 0;
} 
