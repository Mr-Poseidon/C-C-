#include<iostream>
#include<algorithm>
using namespace std;

int n,m,map[101][1001];//nΪʱ�䣬mΪ��ҩ������mapΪ��¼ͼ
int ht,hv;//ht��ҩ�����ʱ�䣬hv��ҩ�ļ�ֵ

int main()
{
	cin>>n>>m;
	for(int i=0;i<=n;i++)//��ʼ���� 
		map[0][i]=0;
	
	for(int i=1;i<=m;i++)
	{
		cin>>ht>>hv;//�����ҩ��ʱ��ͼ�ֵ 
		for(int j=0;j<=n;j++)
		{
			map[i][j]+=map[i-1][j];//����ҩ
			if(j>=ht)//����ҩ�ļ�ֵ�Ͳ���ҩ�ļ�ֵ��ͬ��ѡ�����
				map[i][j]=max(hv+map[i-1][j-ht],map[i][j]);//��ҩ
		}
	}
	cout<<map[m][n]<<endl; 
	/*
	for(int i=1;i<=m;i++)//���ݿ��ӻ�
	{
		for(int j=0;j<=n;j++) 
			cout<<map[i][j]<<" ";
		cout<<endl; 
	}
	*/
	
	return 0;	
}
