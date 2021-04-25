#include<iostream>
#include<algorithm>
using namespace std;

int n=0,ans=0;
int num[100][100],map[100][100];

int dfs(int i,int j)
{
	if(i>=n || j>i)//判断越界 
		return 0;
	
	if(map[i][j]!=-1)
		return map[i][j];
	
	int a,b;
	a=dfs(i+1,j);//左下 
	b=dfs(i+1,j+1);//右下 
	return map[i][j] = max(a,b) + num[i][j];//注意此行,避免重复计算 
}
void init(int n)//初始化数据 
{
	ans=0;//结果置零 
	for(int i=0;i<n;i++)//输入三角形内容 
		for(int j=0;j<=i;j++)
			cin>>num[i][j];
	for(int i=0;i<100;i++)//初始化标记 
		for(int j=0;j<100;j++)
			map[i][j]=-1;
}
int main()
{
	ios::sync_with_stdio(false);//加速 
	cin.tie(0);
	cout.tie(0);
	
	int k=0;//k-测试次数 
	cin>>k;
	while(k)
	{
		cin>>n;//输入行数 
		init(n);//初始化数据
		cout<<dfs(0,0)<<endl;//输出结果 
		k--;
	}
	return 0;
} 
