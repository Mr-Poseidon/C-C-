#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
	char s[205];	
	while(gets(s))//�����ַ��������ո񣡣��� 
	{
		sort(s,s+strlen(s),less<char>());
		cout<<s<<endl;
	}
	
	return 0;
}
