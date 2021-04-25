#include<iostream>
#include<string>
#include<vector>
using namespace std;

//一个大数A * 一个正常int型整数B 
int main()
{
	string a;
	int b;
	cin>>a>>b;
	
	vector<int> A;
	for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
	
	vector<int> C;
	for(int i=0,t=0;i<A.size()||t;i++)
	{
		if(i<A.size())t+=A[i]*b;//此处和加法类似 
		C.push_back(t%10);
		t/=10;
	}
	while(C.size()>1 && C.back()==0)C.pop_back();
	
	for(int i=C.size()-1;i>=0;i--)cout<<C[i];
	return 0;	
} 
