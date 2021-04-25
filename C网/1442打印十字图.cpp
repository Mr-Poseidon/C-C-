#include<iostream>
#include<cstring>
using namespace std;

char map[125][125];
int n,m;

int main()
{
	cin>>n;
	m=4*n+5;
	memset(map,'.',sizeof(map));
	for(int k=1;k<=n+1;k++)
	{
		int t=k*2;
		
		for(int i=t;i<m-t;i++)//四条长边 
		{
			map[t-2][i]='$';//上 
			map[(m-1)-(t-2)][i]='$';//下 
			map[i][t-2]='$';//左 
			map[i][(m-1)-(t-2)]='$';//右
		}
		for(int i=1;i<=2;i++)//四个角 
		{
			map[t-2+i][t]='$';
			map[t-2+i][(m-1)-t]='$';
			map[(m-1)-(t-2+i)][t]='$';
			map[(m-1)-(t-2+i)][(m-1)-t]='$';
			
			map[t][t-2+i]='$';
			map[(m-1)-t][t-2+i]='$';
			map[t][(m-1)-(t-2+i)]='$';
			map[(m-1)-t][(m-1)-(t-2+i)]='$';
		}
	}
	
	for(int i=0;i<m;i++)//输出
	{
		for(int j=0;j<m;j++)
			cout<<map[i][j];	
		cout<<endl;
	}
	 
		
	return 0;
}
