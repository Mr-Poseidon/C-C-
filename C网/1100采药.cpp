#include<iostream>
#include<algorithm>
using namespace std;

int n,m,map[101][1001];//n为时间，m为草药数量，map为记录图
int ht,hv;//ht采药所需的时间，hv草药的价值

int main()
{
	cin>>n>>m;
	for(int i=0;i<=n;i++)//初始置零 
		map[0][i]=0;
	
	for(int i=1;i<=m;i++)
	{
		cin>>ht>>hv;//输入采药的时间和价值 
		for(int j=0;j<=n;j++)
		{
			map[i][j]+=map[i-1][j];//不采药
			if(j>=ht)//若采药的价值和不采药的价值不同则选择大者
				map[i][j]=max(hv+map[i-1][j-ht],map[i][j]);//采药
		}
	}
	cout<<map[m][n]<<endl; 
	/*
	for(int i=1;i<=m;i++)//数据可视化
	{
		for(int j=0;j<=n;j++) 
			cout<<map[i][j]<<" ";
		cout<<endl; 
	}
	*/
	
	return 0;	
}
