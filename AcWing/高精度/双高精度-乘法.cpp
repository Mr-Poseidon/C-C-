#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string a,b;
	cin>>a>>b;
	
	vector<int> A,B;
	for(int i=0;i<a.size();i++)A.push_back(a[i]-'0');
	for(int i=0;i<b.size();i++)B.push_back(b[i]-'0');
	
	vector<int> C(A.size()+B.size(),0);//��ʼ�� 
	for(int i=0;i<A.size();i++)
		for(int j=0;j<B.size();j++)
			C[i+j+1]+=A[i]*B[j];//����������һλ���� 
	for(int i=C.size()-1;i>0;i--)//��λ���� 
	{
		C[i-1]+=C[i]/10;
		C[i]%=10;
	}
	while(C.size()>1 && C.front()==0)C.erase(C.begin());//ɾ��ǰ���� 
	
	for(int i=0;i<C.size();i++)cout<<C[i];//��� 
	
	return 0;
} 
