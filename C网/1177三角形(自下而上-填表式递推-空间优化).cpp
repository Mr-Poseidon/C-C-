/*
ע��
	��̬��������Ե��ƽ����˿ռ��ϵ��Ż�
	�����ڴ�����Ŀ��� 
	�����޷����ӻ��м�ĵ��ƹ���
	�����ڽ���ķ��� 
*/ 


#include<iostream>
#include<algorithm>
#include<cstdlib> 
using namespace std;

int n=0;
int num[100][100];

void init(int n)//��ʼ������ 
{
	for(int i=0;i<n;i++)//��������������
		for(int j=0;j<=i;j++)
			cin>>num[i][j];			
}
int main()
{
	ios::sync_with_stdio(false);//���� 
	cin.tie(0);
	cout.tie(0);
	
	int k=0;//k-���Դ��� 
	cin>>k;
	while(k)
	{
		cin>>n;//�������� 
		init(n);//��ʼ������
		
		int* map=(int*)malloc(n*sizeof(int));//��̬����n��Ԫ�ص�int����ռ� 
		
		for(int i=0;i<n;i++)//��ײ����Ǩ�� 
			map[i]=num[n-1][i];
			 
		for(int i=n-2;i>=0;i--)//���¶��ϵ���
			for(int j=0;j<=i;j++)
			{
				//ע��˴���δ�Ż��ռ�ʱ����кβ�ͬ 
				map[j] = max( map[j] , map[j+1] ) + num[i][j];
			}
		
		cout<<map[0]<<endl;//������ 
		k--;
	}
	return 0;
} 
