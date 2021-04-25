#include<iostream>
#include<string>
using namespace std;

int fun(int num)
{
	int ans=0;
	while(num)
	{
		ans+=num%10;
		num/=10;
	}
	return ans;
}
int main()
{
	string s;
	cin>>s;
	
	int ans=0;
	for(int i=0;i<s.size();i++)
		ans+=s[i]-'0';
	
	while(ans/10!=0)
		ans=fun(ans);
	
	cout<<ans<<endl;
	return 0;
		
} 
