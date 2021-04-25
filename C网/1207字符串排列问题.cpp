#include<iostream>
#include<algorithm>
using namespace std;

int n;
char ch[21];

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>ch[i];
	sort(ch,ch+n);
	
	int ans=0;
	do
	{
		ans++;
	}while(next_permutation(ch,ch+n));
	cout<<ans;
	return 0;
} 
