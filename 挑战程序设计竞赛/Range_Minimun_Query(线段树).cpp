#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 1e9+7
using namespace std;

const int maxn=1<<17;

int n,data[maxn*2-1];

void init(int N)//初始化 
{
	n=1;
	while(n<N)n*=2;
	for(int i=0;i<2*n-1;i++)
		data[i]=INF;
}

//树根(树顶)坐标为0
//自下而上更新 
void update(int k,int num)//将第k个值更新为num 
{
	k+=n-1;//坐标偏移至树的最底部 
	
	data[k]=num;//赋新值 
	
	while(k>0)//向树顶更新，向上更新 
	{
		k=(k-1)/2;
		data[k]=min(data[k*2+1],data[k*2+2]);//求左右子树的最小值 
	}
} 

//求区间[a,b)的最小值
//k,l,r是为了方便计算而传入的
//k是区间[l,r)所对应的节点的编号
//在外部调用时用query(a,b,0,0,n); 
//该查询使用 二分 的递归方法 
//自上而下查询 
int query(int a,int b,int k,int l,int r)//查询 
{
	if(a>=r || b<=l)return INF;//两个区间完全不相交
	
	if(a<=l && r<=b)return data[k];//区间[a,b)完全包含区间[l,r) 
	else//相交，分成左右区间-类似归并 
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
