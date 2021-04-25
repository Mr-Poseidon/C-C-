//认真看题，只做符合要求的事情，注意特殊情况！！！ 

#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int a,b,c;
string s;

string fun(char l,char r)
{
	//   同为数字                                     同为小写字母 
	if( (('0'<=l && l<='9') && ('0'<=r && r<='9')) || ('a'<=l && l<='z') && ('a'<=r && r<='z'))//展开 
	{
		if(l+1==r)return "";
		if(l>=r)return "-";
		
		string ans;
		for(int i=l+1;i<r;i++)
			ans.append(b,(char)i);
		
		if(a==1 && !('0'<=l && l<='9') && !('0'<=r && r<='9'))
		{
			for(int i=0;i<ans.size();i++)
				ans[i]=tolower(ans[i]);
		}
		else if(a==2 && !('0'<=l && l<='9') && !('0'<=r && r<='9'))
		{
			for(int i=0;i<ans.size();i++)
				ans[i]=toupper(ans[i]);
		}
		else if(a==3)
		{
			for(int i=0;i<ans.size();i++)
				ans[i]='*';
		}
		
		if(c==1)return ans;
		else if(c==2)return string(ans.rbegin(),ans.rend());
	}
	return "-";
}
int main()
{
	cin>>a>>b>>c;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if( (i==0||i==s.size()-1) && s[i]=='-')//字符串首尾为- 
		{
			cout<<'-';
			continue;
		}
			
		if(s[i]!='-')
			cout<<s[i];
		else
			cout<<fun(s[i-1],s[i+1]);
	}
	return 0;	
} 
