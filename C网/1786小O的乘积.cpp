#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		vector<int> a,b;
		for(int i=0;i<n;i++)
		{
			int t;
			cin>>t;
			a.push_back(t);
			b.push_back(fabs(t));
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		cout<<min(a[0]*a[n-1],b[0]*b[1])<<endl;
	}
	return 0;
}
