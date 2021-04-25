#include<stdio.h>
#include<string.h> 
int fun(char a[])
{
	int n=strlen(a),f[4]={0};
	if(n<8 || n>16)return 0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>='A' && a[i]<='Z')
		{
			f[0]=1;continue;
		}
		
		if(a[i]>='a' && a[i]<='z')
		{
			f[1]=1;continue;
		}
		
		if(a[i]>='0' && a[i]<='9')
		{
			f[2]=1;continue;
		}
		
		if(a[i]=='~' 
		|| a[i]=='!' || a[i]=='@' || a[i]=='#'
		|| a[i]=='$' || a[i]=='%' || a[i]=='^'
		)
		{
			f[3]=1;continue;
		}
	}
	if((f[0]+f[1]+f[2]+f[3])>=3)return 1;
	return 0;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		char a[17];
		scanf("%s",a);
		if(fun(a))printf("YES\n");
		else printf("NO\n");
	}
}
