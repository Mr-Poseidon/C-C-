#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int N=1000010;

typedef vector<int> vec;

bool cmp(vec& A,vec& B)//�ж�A�Ƿ����B 
{
	if(A.size()!=B.size())return A.size()>B.size();
	for(int i=A.size()-1;i>=0;i--)//�����Ǹ�λ 
		if(A[i]!=B[i])
			return A[i]>B[i];
	return true;//������� 
} 
vec sub(vec& A,vec& B)// C=A-B ���� A>B , A>0 , B>0  
{
	vec C;
	for(int i=0,t=0;i<A.size();i++)
	{
		t=A[i]-t;//����A[i],��ȥ��λ 
		if(i<B.size())t-=B[i];
		C.push_back((t+10)%10);// 2-5=-3  ->   12-5=7
		if(t<0)t=1;//t<0�����н�λ 
		else t=0;
	}
	while(C.size()>1 && C.back()==0)C.pop_back();//ȥ��ǰ����
	return vec(C.rbegin(),C.rend());//��ת
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
