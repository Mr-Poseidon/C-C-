#include<iostream>
using namespace std;

//ans[][0]�ų�����ans[][1]������
unsigned long long int n,ans[2][2]={1,1,0,0};//������Ŀ�����ֵ 


void common_min_remainder()//����Сͬ�������������ans[0][]�� 
{
	while(ans[0][1]!=ans[1][1])
	{
		if(ans[0][1]<ans[1][1])
			ans[0][1]+=ans[0][0];
		else
			ans[1][1]+=ans[1][0];
	}
	ans[0][0]*=ans[1][0];
	return ;
}
int main()
{
	cin>>n; 
	cin>>ans[0][0]>>ans[0][1];//�����һ������ 

	for(int i=0;i<n-1;i++)
	{
		cin>>ans[1][0]>>ans[1][1];
		common_min_remainder();//����Сͬ���� 
	}
	cout<<ans[0][1]<<endl;//������ 
	return 0;
} 
