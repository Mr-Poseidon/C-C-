#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int field=1;//区域标志 

void fun(int a,int b)
{
	char** map=(char**)malloc(sizeof(char*)*a);//动态开辟数组 
	for(int i=0;i<a;i++)
		map[i]=(char*)malloc(sizeof(char)*b);
	
	for(int i=0;i<a;i++)//输入地图 
	{
		for(int j=0;j<b;j++)
			scanf("%c",&map[i][j]);
		getchar();//消化换行符 
	}
		
	
	for(int i=0;i<a;i++)//遍历地图并处理 
		for(int j=0;j<b;j++)
		{
			if(map[i][j]=='*')
				continue;
			else//计算周边地雷数量 
			{
				int num=0;
				for(int k=-1;k<=1;k++)
					for(int l=-1;l<=1;l++)
					{
						if(i+k<0 || i+k>=a)continue;
						if(j+l<0 || j+l>=b)continue;
						if(k==0 && l==0)continue;
						if(map[i+k][j+l]=='*')
							num++;
					}
				map[i][j]='0'+num;//标记地雷数量 
			}
		}
	
	cout<<"Field #"<<field<<":"<<endl;//输出地图 
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
			printf("%c",map[i][j]);
		printf("\n");
	}
	
	for(int i=0;i<a;i++)//释放动态数组 
		free(map[i]);
	free(map);
	field++;//区域标志自加	
}
int main()
{
	int a,b; 
	while(~scanf("%d%d",&a,&b) && a!=0 && b!=0)
	{
		getchar();//消化换行符，避免对接下来字符的输入造成影响 
		fun(a,b);
		cout<<endl;//区域间空行隔开 
	}	
	return 0;
}
