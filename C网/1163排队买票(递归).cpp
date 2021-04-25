#include<stdio.h>
int ans,na,ka;
void fun(int m,int n,int k)
{
	if(ka>na)return;
	if(m==0)	
	{
		ans++;return;
	}
	
	for(int i=k;i>0;i--)
	{
		ka++;
		fun(m-1,n,k-1);
		ka--;
	}
		
	for(int i=n;i>0;i--)
	{
		na++;
		fun(m-1,n-1,k);
		na--;
	}
	return;
}
int main()
{
	int m,n,k;
	while(~scanf("%d%d%d",&m,&n,&k))
	{
		ans=0,na=0,ka=0;
		fun(m,n,k);
		printf("%d",ans);
	}
	return 0;
}

