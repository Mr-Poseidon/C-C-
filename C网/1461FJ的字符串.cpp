#include<iostream>
#include<string>
using namespace std;

int n;

string fun(string s,int k)
{
	s=s+(char)('A'-1+k)+s;
	if(k==n)return s;
	else return fun(s,k+1);
}
int main()
{
	cin>>n;
	cout<<fun("",1)<<endl;
	return 0;	
} 
