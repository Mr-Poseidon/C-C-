#include<iostream>
#include<string> 
using namespace std;

void fun(string& s,int i,int j)
{
	if(i>=j)return;
	swap(s[i],s[j]);//���������ַ�
	cout<<s<<endl;//��� 
	fun(s,i+1,j-1);
}
int main()
{
	int n;
	string s;
	cin>>n>>s;
	fun(s,0,s.size()-1);
	cout<<endl<<s;
	return 0;
}
