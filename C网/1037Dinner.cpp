#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int n;
string str[4]={"bowl","knife","fork","chopsticks"};
int main()
{
	while(~scanf("%d",&n))
	{
		int k=0;
		for(int i=0;i<n;i++)//�������� 
		{
			string t;
			cin>>t;
			for(int j=0;j<4;j++)//�ж��Ƿ���Ҫ��� 
				if(t.compare(str[j])==0)
				{
					if(k)cout<<" ";
					cout<<t;
					k++;
				}
		}
		cout<<endl;
	}
	return 0;
}
