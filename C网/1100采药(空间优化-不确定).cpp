#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

int n,m,*map=NULL;//nΪʱ�䣬mΪ��ҩ������mapΪ��¼ͼ
int ht,hv;//ht��ҩ�����ʱ�䣬hv��ҩ�ļ�ֵ

int main()
{
	cin>>n>>m;
	map=(int*)malloc((n+1)*sizeof(int));//������¼ͼ 
	for(int i=0;i<=n;i++)//��ʼ���� 
		map[i]=0;
	
	for(int i=1;i<=m;i++)
	{
		cin>>ht>>hv;//�����ҩ��ʱ��ͼ�ֵ 
		int *t=(int*)malloc((n+1)*sizeof(int));//������ʱ��¼ͼ 
		for(int j=0;j<=n;j++)t[j]=0;//��ʱ��¼ͼ��ʼ����
		 
		for(int j=0;j<=n;j++)
		{
			t[j]+=map[j];//����ҩ
			if(j>=ht)//����ҩ�ļ�ֵ�Ͳ���ҩ�ļ�ֵ��ͬ��ѡ�����
				t[j]=max(hv+map[j-ht],map[j]);//��ҩ
		}
		map=t;//���汾�μ�¼ͼ 
		/* 
		for(int j=0;j<=n;j++)//���ݿ��ӻ� 
			cout<<map[j]<<" ";
		cout<<endl;
		*/ 
	}
	cout<<map[n]<<endl; 
	
	return 0;	
}
