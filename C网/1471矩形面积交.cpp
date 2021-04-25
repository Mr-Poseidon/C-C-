#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

double a[2][4],d[2][4];//[0-x/y-1][第几个点]

int main()
{
	for(int i=0;i<4;i++)
		cin>>d[0][i]>>d[1][i];

	sort(d[0],d[0]+2);
	sort(d[0]+2,d[0]+4);
	sort(d[1],d[1]+2);
	sort(d[1]+2,d[1]+4);	
	
	for(int i=0;i<2;i++)
		for(int j=0;j<4;j++)
			a[i][j]=d[i][j];
			
	sort(d[0],d[0]+4);
	sort(d[1],d[1]+4);
	
	/*	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<4;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<4;j++)
			cout<<d[i][j]<<" ";
		cout<<endl;
	}
	*/	
	
	if(a[0][0]<=d[0][1] && d[0][1]<=a[0][1])//x
	if(a[0][2]<=d[0][1] && d[0][1]<=a[0][3])
		if(a[0][0]<=d[0][2] && d[0][2]<=a[0][1])
		if(a[0][2]<=d[0][2] && d[0][2]<=a[0][3])
			if(a[1][0]<=d[1][1] && d[1][1]<=a[1][1])//y
			if(a[1][2]<=d[1][1] && d[1][1]<=a[1][3])
				if(a[1][0]<=d[1][2] && d[1][2]<=a[1][1])
				if(a[1][2]<=d[1][2] && d[1][2]<=a[1][3])
				{
					printf("%.2lf",((double)(d[0][2]-d[0][1])*(d[1][2]-d[1][1])));
					return 0;
				}
	
	printf("%.2lf",0);
	return 0;
}
