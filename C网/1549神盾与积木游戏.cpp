#include<iostream>
#include<algorithm>
using namespace std;

struct block{
	int have,need;
};
bool cmp(block a,block b)//拥有积木多的，需要的少的在前面 
{
	return a.have-a.need>b.have-b.need;
}
block f[10005];

bool fun()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>f[i].have>>f[i].need;
	sort(f,f+n,cmp);
	
	int h=0;
	for(int i=0;i<n;i++)
	{
		if(h+f[i].have>=f[i].need)h+=f[i].have;
		else return false;
	}
	return true;
}
int main()
{
	int m;
	cin>>m;
	while(m--)
	{
		if(fun())cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
