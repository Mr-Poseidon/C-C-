#include<iostream>
#include<cstdio>
using namespace std;

int a,b;//��ʿ���� 
int d[8][2]={-1,2,1,2,-1,-2,1,-2,2,1,2,-1,-2,1,-2,-1};//�˸����� 

int fun()
{
	int ans=0;
	scanf("%c%d",&a,&b);//�������� 
	getchar();//�������������\n 
	a-='a'-1;//����ĸת�������� 
	for(int i=0;i<8;i++)//�����˸����� 
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
