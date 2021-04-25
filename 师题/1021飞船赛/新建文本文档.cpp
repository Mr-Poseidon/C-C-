#include<stdio.h>
int a[250000]=0;
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int ans=0;
		for(int i=0;i<n;i++)
			scanf("%*d%d",&a[i]);
		scanf("%*d");
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
				if(a[i]>a[j])ans++;
			ans=ans%1000000;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
