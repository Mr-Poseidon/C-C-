#include<iostream>
#include<cstdio>
#include<string> 
using namespace std;

int n;
string s,t;
 
int main()
{ 
	cin>>n;
	while(n--)
	{
		cin>>s;
		if(s.compare("WYS")==0)
		{
			cout<<"KXZSMR"<<endl;
			continue;
		}
		if(s.compare("CQ")==0)
		{
			cout<<"CHAIQIANG"<<endl;
			continue;
		}
		if(s.compare("LC")==0)
		{
			cout<<"DRAGONNET"<<endl;
			continue;
		}
		if(s.compare("SYT")==0)
		{
			cout<<"STUDYFATHER"<<endl;
			continue;
		}
		if(s.compare("SSD")==0)
		{
			cout<<"STUDYFATHER"<<endl;
			continue;
		}
		if(s.compare("LSS")==0)
		{
			cout<<"STUDYFATHER"<<endl;
			continue;
		}
		if(s.compare("LYF")==0)
		{
			cout<<"STUDYFATHER"<<endl;
			continue;
		}
		cout<<"DENOMINATOR"<<endl;
	}
	return 0;
} 
