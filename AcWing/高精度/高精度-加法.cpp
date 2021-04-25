#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string a,b;
	vector<int> A,B;
	cin>>a>>b;
	for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');//前面是低位,后面是高位 
	for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');
	vector<int> C;
	for(int i=0,t=0;i<A.size() || i<B.size() || t;i++)
	{
		if(i<A.size())t+=A[i];
		if(i<B.size())t+=B[i];
		C.push_back(t%10);
		t/=10;
	}
	for(int i=C.size()-1;i>=0;i--)cout<<C[i];
	return 0;
} 
