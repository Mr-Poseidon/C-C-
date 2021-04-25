#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 1e9+7
using namespace std;

const int maxn=1<<17;

int n,data[maxn*2-1];

void init(int N)//��ʼ�� 
{
	n=1;
	while(n<N)n*=2;
	for(int i=0;i<2*n-1;i++)
		data[i]=INF;
}

//����(����)����Ϊ0
//���¶��ϸ��� 
void update(int k,int num)//����k��ֵ����Ϊnum 
{
	k+=n-1;//����ƫ����������ײ� 
	
	data[k]=num;//����ֵ 
	
	while(k>0)//���������£����ϸ��� 
	{
		k=(k-1)/2;
		data[k]=min(data[k*2+1],data[k*2+2]);//��������������Сֵ 
	}
} 

//������[a,b)����Сֵ
//k,l,r��Ϊ�˷������������
//k������[l,r)����Ӧ�Ľڵ�ı��
//���ⲿ����ʱ��query(a,b,0,0,n); 
//�ò�ѯʹ�� ���� �ĵݹ鷽�� 
//���϶��²�ѯ 
int query(int a,int b,int k,int l,int r)//��ѯ 
{
	if(a>=r || b<=l)return INF;//����������ȫ���ཻ
	
	if(a<=l && r<=b)return data[k];//����[a,b)��ȫ��������[l,r) 
	else//�ཻ���ֳ���������-���ƹ鲢 
	{
		int vl=query(a,b,k*2+1,l,(l+r)/2);
		int vr=query(a,b,k*2+2,(l+r)/2,r);
		return min(vl,vr);
	}
}
int main()
{
	return 0;
} 
