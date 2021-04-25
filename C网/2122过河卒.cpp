#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int map[22][22];
int vis[22][22];
int n,m,ans=0;

bool is_dot(int x,int y)
{
	if(0<=x && x<=n && 0<=y && y<=m)
		return true;
	else return false;
}
void gethorse()
{
	int x,y;
	cin>>x>>y;
	vis[x][y]=1;
	
	for(int i=-2;i<=2;i++)
	{
		if(i==0)continue;
		for(int j=-2;j<=2;j++)
		{
			if(j==0)continue;
			if(abs(i)==abs(j))continue;
			if(is_dot(x+i,y+j))
				vis[x+i][y+j]=1;
		}
	}	
	return;
}
int main()
{
	memset(map,0,sizeof(map));
	memset(vis,0,sizeof(vis));
	
	cin>>n>>m;
	gethorse();
	
	for(int i=0;i<=m;i++)//第一行只能横着走，所有格只有一种方法 
	{
		if(vis[0][i]==1)break;
		else map[0][i]=1;
	}
	for(int i=0;i<=n;i++)//第一列只能竖着走，所有格只有一种方法
	{
		if(vis[i][0]==1)break;
		else map[i][0]=1;
	}
	for(int i=1;i<=n;i++)//从第二行第二列开始 
		for(int j=1;j<=m;j++)
		{
			if(vis[i][j]==1)continue; 
			//        上一格   +  左一格 
			map[i][j]=map[i-1][j]+map[i][j-1];//状态转移 
		}
	cout<<map[n][m];
	return 0;
}
