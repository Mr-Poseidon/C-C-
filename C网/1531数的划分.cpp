#include<iostream>
using namespace std;

int n,map[105][105];//map[]-记录图

int main()
{
	cin>>n;
	//注：此处map[1][0]进行赋值1，代替了当i==j时，map[i][j]++ 
	for(int i=0;i<=n;i++)//当只选1的时候，每个数结果都只有一种 
		map[1][i]=1;
		
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			//代码简化 
			map[i][j]=map[i-1][j];//在不用i时，凑出j的方案数同等于不能用i时凑出j的方案数
			if(j>=i)
				map[i][j]+=map[i][j-i];//用i时，凑出j的方案数要加上凑出j-i的方案数 
			 
			
			/* 
			//注：正常理解---上下代码结果相同 
			map[i][j]=map[i-1][j];//在不用i时，凑出j的方案数同等于不能用i时凑出j的方案数
			if(j==i)
				map[i][j]++;//当可用数i刚好等于j时，只有一种方案，只用本身这一个数 
			if(j>i)
				map[i][j]+=map[i][j-i];//用i时，凑出j的方案数要加上凑出j-i的方案数。
			*/ 
		}
	}
	/* 
	for(int i=1;i<=n;i++)//结果可视化 
	{
		for(int j=0;j<=n;j++)
			cout<<map[i][j]<<" ";
		cout<<endl;
	}
	*/ 
	cout<<map[n][n]<<endl;
	return 0;
}
