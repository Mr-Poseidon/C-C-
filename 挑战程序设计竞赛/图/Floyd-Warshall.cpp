#include<iostream>
#include<algorithm>
#define maxv 1000
using namespace std;

int d[maxv][maxv];
int v;

/*
	ִ��һ�ο������ ���ⶥ�� �� ���ⶥ�� ����̾���
	���벻����ʱ��ΪINF
	���Դ������ ���� ����� 
	ִ�к�������d[i][i]Ϊ����������ڸ�Ȧ 
*/
void floyd_warshall()
{
	for(int k=0;k<v;k++)//�����ȱ���������
		for(int i=0;i<v;i++)//������
			for(int j=0;j<v;j++)//�յ����
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);//���~������ + ������~�յ� 
}

int main()
{
	return 0;
}
