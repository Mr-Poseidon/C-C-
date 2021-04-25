#include<iostream>
#include<cstdio> 
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<string> ans;
	string ss;
	char cc[105];
	getline(cin,ss);
	ss=ss+" ";
	while(!ss.empty())
	{
		bool f=false;	
		sscanf(ss.c_str(),"%s",cc);
		string t(cc);
		for(vector<string>::iterator it=ans.begin();it!=ans.end();it++)
			if(*it==t)
				f=true;
		if(!f)
			ans.push_back(t);
		while(ss[0]!=' ')
			ss.erase(0,1);
		ss.erase(0,1);
	}
	/*
	for(vector<string>::iterator it=ans.begin();it!=ans.end();it++)
			cout<<*it<<" ";
	*/
	cout<<ans.size();
	return 0;
}
