#include<iostream>
using namespace std;

int n,p[2005];
int ga,gb;
int main()
{
	while(cin>>n)
	{
		ga=0;
		gb=0;
		for(int i=0;i<=2000;i++)
			p[i]=i;
		while(n--)
		{
			int a,b;
			cin>>a>>b;
			p[a]=b;
		}
		
		int s=1;
		while(s!=p[s])
		{
			ga++;
			s=p[s];
		}
		s=2;
		while(s!=p[s])
		{
			gb++;
			s=p[s];
		}
		
		if(ga>gb)
			cout<<"You are my elder"<<endl;
		else if(ga==gb)
			cout<<"You are my brother"<<endl;
		else
			cout<<"You are my younger"<<endl;	
	}
	return 0;
} 
