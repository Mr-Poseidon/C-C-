#include<stdio.h>
#include<stdlib.h>
int fun(int n,int m)
{
	int* a=(int*)calloc(n,4);
	int outnum=n-1,t=0;
	for(int i=0;i>=0;i++)
	{
		if(a[i%n]!=1)
			t++;
		if(m==t)
		{
			a[i%n]=1;
			t=0;
			outnum--;
		}
		if(outnum==0)
			break;
	}
	
	for(int i=0;i<n;i++)
		if(a[i]==0)
		{
			free(a);
			return i+1;
		}
		
}
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		printf("%d\n",fun(n,m));
	}
	return 0;
}
