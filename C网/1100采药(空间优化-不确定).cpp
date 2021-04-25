#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

int n,m,*map=NULL;//n为时间，m为草药数量，map为记录图
int ht,hv;//ht采药所需的时间，hv草药的价值

int main()
{
	cin>>n>>m;
	map=(int*)malloc((n+1)*sizeof(int));//创建记录图 
	for(int i=0;i<=n;i++)//初始置零 
		map[i]=0;
	
	for(int i=1;i<=m;i++)
	{
		cin>>ht>>hv;//输入采药的时间和价值 
		int *t=(int*)malloc((n+1)*sizeof(int));//创建临时记录图 
		for(int j=0;j<=n;j++)t[j]=0;//临时记录图初始置零
		 
		for(int j=0;j<=n;j++)
		{
			t[j]+=map[j];//不采药
			if(j>=ht)//若采药的价值和不采药的价值不同则选择大者
				t[j]=max(hv+map[j-ht],map[j]);//采药
		}
		map=t;//储存本次记录图 
		/* 
		for(int j=0;j<=n;j++)//数据可视化 
			cout<<map[j]<<" ";
		cout<<endl;
		*/ 
	}
	cout<<map[n]<<endl; 
	
	return 0;	
}
