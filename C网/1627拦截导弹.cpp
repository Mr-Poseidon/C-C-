#include<iostream>
#include<vector>
#include<algorithm>
#define INF 1e6
using namespace std;

typedef vector<int> vec;

//LIS最长递增子序列-Longest increasing subsequence 

vec lnds(vec num)//LNDS最长不下降子序列-Longest non descending subsequence
{
	vec t(num.size(),INF);
	for(int i=0;i<num.size();i++)
		*upper_bound(t.begin(),t.end(),num[i])=num[i];
	while(t.back()==INF)
		t.pop_back();
	return t;
}

int main()
{
	vector<int> num;
	
	int t;
	while(cin>>t) 
	{
		//if(t==0)break;//注意要改
		num.push_back(t);
	}	
	num=vector<int>(num.rbegin(),num.rend());//翻转 
	
	int count=0;
	for(int i=1;!num.empty();i++)
	{
		vec tt;
		tt=lnds(num);
		if(i==1)
			cout<<tt.size()<<endl;//输出lnds的长度 
		count++;//计算lnds的数量 
		
		for(int j=0;j<tt.size();j++)//删除元素 
			for(int k=0;k<num.size();k++)
				if(tt[j]==num[k])
				{
					num.erase(num.begin()+k);
					break;
				}
	}
	cout<<count; 
	return 0;
}
