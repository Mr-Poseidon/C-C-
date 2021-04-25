#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int N=1000010;

typedef vector<int> vec;

bool cmp(vec& A,vec& B)//判断A是否大于B 
{
	if(A.size()!=B.size())return A.size()>B.size();
	for(int i=A.size()-1;i>=0;i--)//后面是高位 
		if(A[i]!=B[i])
			return A[i]>B[i];
	return true;//两数相等 
} 
vec sub(vec& A,vec& B)// C=A-B 满足 A>B , A>0 , B>0  
{
	vec C;
	for(int i=0,t=0;i<A.size();i++)
	{
		t=A[i]-t;//加上A[i],减去借位 
		if(i<B.size())t-=B[i];
		C.push_back((t+10)%10);// 2-5=-3  ->   12-5=7
		if(t<0)t=1;//t<0代表有借位 
		else t=0;
	}
	while(C.size()>1 && C.back()==0)C.pop_back();//去除前导零
	return vec(C.rbegin(),C.rend());//翻转
}
 
int main()
{
	string a,b;
	vector<int> A,B;
	cin>>a>>b;
	for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
	for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');
	
	vector<int> C;
	if(cmp(A,B))C=sub(A,B);
	else C=sub(B,A);
	
	for(int i=0;i<C.size();i++)cout<<C[i];
	return 0;
} 
