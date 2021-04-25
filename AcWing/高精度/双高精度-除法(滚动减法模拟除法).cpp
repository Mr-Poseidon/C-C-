#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef vector<int> vec;

int cmp(vec A,vec B)//比较大小 > = < 对应 1 0 -1 
{
	if(A.size()!=B.size())
		if(A.size()>B.size())return 1;
		else return -1;
	for(int i=0;i<A.size();i++)
		if(A[i]!=B[i])
			if(A[i]>B[i])return 1;
			else return -1;
	return 0;
}

vec sub(vec A,vec B)//减法 
{
	A=vec(A.rbegin(),A.rend());
	B=vec(B.rbegin(),B.rend());
	
	vec C;
	for(int i=0,t=0;i<A.size();i++)
	{
		t=A[i]-t;
		if(i<B.size())t-=B[i];
		C.push_back((t+10)%10);
		if(t<0)t=1;
		else t=0;
	}
	while(C.size()>1 && C.back()==0)C.pop_back();
	
	return vec(C.rbegin(),C.rend());
}

pair<vec,vec> div(vec A,vec B)//滚动减法模拟除法 
{
	int initsize=B.size();//记录除数的初始位数 
	while(A.size()>B.size())B.push_back(0);//除数扩大到极限 
	
	vec C;
	while(1)
	{
		int t=0;//减的次数 
		for(t=0;cmp(A,B)>=0;t++)A=sub(A,B);//A>=B就减 
		C.push_back(t); 
		if(B.size()==initsize)break;//到达除数本身,除法结束 
		else B.pop_back();//除数%10 
	}
	while(C.size()>1 && C.front()==0)C.erase(C.begin());//去除前导0 
	
	return pair<vec,vec>(C,A);//返回结果 
}

int main()
{
	string a,b;
	cin>>a>>b;
	
	vector<int> A,B;
	for(int i=0;i<a.size();i++)A.push_back(a[i]-'0');
	for(int i=0;i<b.size();i++)B.push_back(b[i]-'0');
	
	pair<vec,vec> C;
	C=div(A,B);//A除B,返回值为 商和余 
	
	vec t=C.first;//输出 
	for(int i=0;i<t.size();i++)cout<<t[i];
	cout<<endl;
	t=C.second;
	for(int i=0;i<t.size();i++)cout<<t[i];
	
	return 0;
}
