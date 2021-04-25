#include<iostream>
using namespace std;

int s[1000010];
int n,m,l,r;

int main()//ǰ׺�Ͳ�ѯ 
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i],s[i]+=s[i-1];
	while(m--)cin>>l>>r,cout<<s[r]-s[l-1]<<endl;
	return 0;
} 
