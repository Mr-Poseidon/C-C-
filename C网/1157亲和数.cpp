#include<stdio.h>
int test(int num)
{
	int sum=0,n=num/2;
	for(int i=1;i<=n;i++)
		if(num%i==0)
			sum+=i;
	return sum;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(test(a)==b && test(b)==a)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
} 
