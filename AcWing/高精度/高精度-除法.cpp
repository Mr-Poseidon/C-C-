#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	string a;
	int b;
	cin>>a>>b;
	
	vector<int> A;
	for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
	
	vector<int> C;
	for(int i=A.size()-1,t=0;i>=0;i--) 
	{
		t*=10;
		t+=A[i];
		C.push_back(t/b);
		t%=b;
	}
	while(C.size()>1 && C.front()==0)C.erase(C.begin());//È¥³ýÇ°µ¼0 
	
	for(int i=0;i<C.size();i++)cout<<C[i];
	
	return 0;
} 
