#include<iostream>
#include<vector>
#include<algorithm>
#define INF 1e6
using namespace std;

typedef vector<int> vec;

//LIS�����������-Longest increasing subsequence 

vec lnds(vec num)//LNDS����½�������-Longest non descending subsequence
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
		//if(t==0)break;//ע��Ҫ��
		num.push_back(t);
	}	
	num=vector<int>(num.rbegin(),num.rend());//��ת 
	
	int count=0;
	for(int i=1;!num.empty();i++)
	{
		vec tt;
		tt=lnds(num);
		if(i==1)
			cout<<tt.size()<<endl;//���lnds�ĳ��� 
		count++;//����lnds������ 
		
		for(int j=0;j<tt.size();j++)//ɾ��Ԫ�� 
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
