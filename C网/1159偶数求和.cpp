#include<stdio.h>
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		int sum=0,t=0;
		for(int i=1;i<=n;i++)
		{
			sum+=2*i;
			t++;
			if(t==m)
			{
				printf("%d ",sum/m);
				sum=0;
				t=0;
			}
		}
		if(t!=0)printf("%d ",sum/t);
		printf("\n");
	}
	return 0;
}
