/*
注：
	动态开辟数组对递推进行了空间上的优化
	减少内存上面的开销 
	但是无法可视化中间的递推过程
	不利于结果的分析 
*/ 


#include<iostream>
#include<algorithm>
#include<cstdlib> 
using namespace std;

int n=0;
int num[100][100];

void init(int n)//初始化数据 
{
	for(int i=0;i<n;i++)//输入三角形内容
		for(int j=0;j<=i;j++)
			cin>>num[i][j];			
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
		
		int* map=(int*)malloc(n*sizeof(int));//动态开辟n个元素的int数组空间 
		
		for(int i=0;i<n;i++)//最底层进行迁移 
			map[i]=num[n-1][i];
			 
		for(int i=n-2;i>=0;i--)//自下而上递推
			for(int j=0;j<=i;j++)
			{
				//注意此处和未优化空间时相比有何不同 
				map[j] = max( map[j] , map[j+1] ) + num[i][j];
			}
		
		cout<<map[0]<<endl;//输出结果 
		k--;
	}
	return 0;
} 
