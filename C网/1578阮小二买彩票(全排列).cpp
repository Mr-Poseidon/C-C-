#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	string s;
	cin>>s;
	sort(s.begin(),s.end(),less<char>());
	
	do
	{
		cout<<s<<endl;
	}while(next_permutation(s.begin(),s.end()));
	return 0;
} 
