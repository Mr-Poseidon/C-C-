#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int n; 
char t[1000]={'\0'};
string str;

int main()
{
	cin>>n;
	getchar();
	for(int i=0;i<n;i++)
	{
		string str;
		char ch;
		while(~scanf("%c",&ch) && ch!='\n')
			str.append(1,ch);
		cout<<str<<endl<<endl;
	}
	while(~scanf("%s",t))
		printf("%s\n\n",t);
	return 0;
}
