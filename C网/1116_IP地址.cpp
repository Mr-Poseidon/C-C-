#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
	string s;
	while(cin>>s)
	{
		char ss[35];
		strcpy(ss,s.c_str());
		bool f=true;
		int a[4];
		for(int i=0;i<s.size();i++)
		{
			if((s[i]<'0' || s[i]>'9')&&(s[i]!='.'))
			{
				cout<<"N"<<endl;
				f=false;
				break;
			}
		}
		if(f==false)
			continue;
			
		if(sscanf(ss,"%d.%d.%d.%d",&a[0],&a[1],&a[2],&a[3])==4)
		{
			for(int i=0;i<4;i++)
				if(a[i]<0 || a[i]>255)
				{
					f=false;
					break;
				}
		}
		if(f==false)
			cout<<"N"<<endl;
		else
			cout<<"Y"<<endl;
	}
	return 0;
} 
