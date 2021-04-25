#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
	int n,out=3;
	cin>>n;
	bool* p=(bool*)malloc(n*sizeof(bool));
	
	for(int i=0;i<n;i++)
		p[i]=true;
	int out_num=n-1;
	while(1)
	{
		int t=0;
		for(int k=0;k>=0;k++)
		{
			if(p[k%n])
				t++;
			if(t==out)
			{
				t=0;
				p[k%n]=false;
				out_num--;
				if(out_num==0)
				{
					for(int i=0;i<n;i++)
						if(p[i])
						{
							cout<<i+1<<endl;
							return 0;
						}	
				}
			}
		}
	}
	return 0;
}
