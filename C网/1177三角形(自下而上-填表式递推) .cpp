#include<iostream>
#include<algorithm>
using namespace std;

int n=0;
int num[100][100],map[100][100];

void init(int n)//初始化数据 
{
	for(int i=0;i<n;i++)//输入三角形内容并标记 
		for(int j=0;j<=i;j++)
		{
			cin>>num[i][j];
			map[i][j]=0;
		}			
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
		
		for(int i=0;i<n;i++)//最底层进行迁移 
			map[n-1][i]=num[n-1][i];
			 
		for(int i=n-2;i>=0;i--)//自下而上递推
			for(int j=0;j<=i;j++)
			{
				map[i][j] = max( map[i+1][j] , map[i+1][j+1] ) + num[i][j];
			}
		
		cout<<map[0][0]<<endl;//输出结果 
		k--;
	}
	return 0;
} 
