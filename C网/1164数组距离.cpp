#include<stdio.h>
#include<math.h>
#define INF 99999999
int f[1001],g[1001];
int main()
{
	int m,n,ans;
	while(~scanf("%d%d",&m,&n))
	{
		ans=INF;
		for(int i=0;i<m;i++)
			scanf("%d",&f[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&g[i]);
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				int t=fabs((f[i]-g[j]));
				if(t<ans)ans=t;
			}
		printf("%d",ans);
	}
	return 0;
} 
