#include<stdio.h>
int x,y,sum;
int main()
{
	while(~scanf("%d%d",&x,&y))
	{
		sum=0;
		for(int i=x;i<=y;i++)
		{
			if(i%3==1 && i%5==3)
				sum+=i;
		}
		printf("%d",sum);
	}
	return 0;
}
