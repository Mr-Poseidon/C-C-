#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
6 3
1 3 3 4 4 6
2
8
3

输出
1 0
-1 -1
1 2
标准答案
-1 -1
-1 -1
1 2
*/
int main()
{
	int a[]={1,3,3,4,4,6};
	vector<int> b(a,a+6);
	pair<vector<int>::iterator,vector<int>::iterator> p;
	p=equal_range(b.begin(),b.end(),5);
	
	cout<<*p.first<<" "<<*p.second<<endl;
	if(p.first==p.second && *p.first!=5)
		cout<<"-1 -1"<<endl;
	else
		cout<<p.first-b.begin()<<" "<<p.second-b.begin()-1<<endl;
	return 0; 
} 
