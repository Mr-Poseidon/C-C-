#include<string.h>
#include<stdio.h>

int fun(char *a)
{
	int len=0;
	char t[81]={'\n'};
	while(a[len]=='*')
			t[len++]='*';
	for(int i=len;i<strlen(a);i++)
	{
		if(a[i]!='*')
			t[len++]=a[i];	
	}
	strcpy(a,t);
    return 0;
}

int main()
{
    char s[81];
    gets(s);
    fun(s);
    puts(s);
    return 0;
}
