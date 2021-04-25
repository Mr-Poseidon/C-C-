#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef vector<int> vec;

int k;//进制 
string a;//大数 

bool test(vec A)//判断是否回文 
{
	for(int i=0,j=A.size()-1;i<j;i++,j--)
		if(A[i]!=A[j])
			return false;
	return true;
}
vec rev(vec A)//翻转 
{
	A=vec(A.rbegin(),A.rend());
	while(A.size()>1 && A.front()==0)A.erase(A.begin());
	return A;
}
vec add(vec A,vec B)//相加 
{
	A=vec(A.rbegin(),A.rend());
	B=vec(B.rbegin(),B.rend());
	
	vec C; 
	for(int i=0,t=0;i<A.size()||i<B.size()||t;i++)
	{
		if(i<A.size())t+=A[i];
		if(i<B.size())t+=B[i];
		C.push_back(t%k);
		t/=k;
	}
	
	return vec(C.rbegin(),C.rend());
}
int main()
{
	cin>>k>>a;
	
	vector<int> A;
	for(int i=0;i<a.size();i++)//特殊进制特殊处理,16进制会有两种字母形式 
		if('0'<=a[i] && a[i]<='9')A.push_back(a[i]-'0');
		else if('A'<=a[i] && a[i]<='Z')A.push_back(a[i]-'A'+10);
		else if('a'<=a[i] && a[i]<='z')A.push_back(a[i]-'a'+10);
		
	for(int i=1;i<=30;i++)//判断次数 
	{
		A=add(A,rev(A));
		if(test(A))
		{
			cout<<i;
			return 0;
		}
	}
	cout<<"Impossible";
	return 0;
}
