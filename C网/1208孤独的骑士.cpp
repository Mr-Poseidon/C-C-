#include<iostream>
#include<cstdio>
using namespace std;

int a,b;//骑士坐标 
int d[8][2]={-1,2,1,2,-1,-2,1,-2,2,1,2,-1,-2,1,-2,-1};//八个方向 

int fun()
{
	int ans=0;
	scanf("%c%d",&a,&b);//输入坐标 
	getchar();//消化输入产生的\n 
	a-='a'-1;//将字母转换成数字 
	for(int i=0;i<8;i++)//遍历八个方向 
	{
		int x=a+d[i][0];
		int y=b+d[i][1];
		if(x>0 && x<9 && y>0 && y<9)
			ans++;
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	getchar();
	while(n--)
		cout<<fun()<<endl;
	return 0;
} 
