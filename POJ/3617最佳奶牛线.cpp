#include<iostream>
#include<cstdio>
using namespace std;

int n;
char s[2005]; 

int main()
{
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++)
	{
		scanf("%c",&s[i]);
		getchar();
	}
	
	int l=0,r=n-1,count=0;
	while(l<=r)
	{
		bool left=false;
		for(int i=0;l+i <= r-i;i++)
		{
			if(s[l+i]<s[r-i])
			{
				left=true;
				break;
			}
			else if(s[l+i]>s[r-i])
			{
				left=false;
				break;
			}
		}
		
		if(left)putchar(s[l++]);
		else putchar(s[r--]);
		count++;//记录输出字母的数量 
		
		if(count%80==0)putchar('\n');//80个字母要换行 
	}
	putchar('\n');
	return 0;
}
