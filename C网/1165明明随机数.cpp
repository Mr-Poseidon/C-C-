#include<stdio.h>
#include<string.h>
int a[1002],n,ans;
int main()
{
	while(~scanf("%d",&n))
	{
		ans=n;
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
		{
			int t;
			scanf("%d",&t);
			if(!a[t])
				a[t]=1;
			else
				ans--;
		}
		printf("%d\n",ans);
		for(int i=0;i<1000;i++)
			if(a[i])printf("%d ",i);
	}
	return 0;
}
