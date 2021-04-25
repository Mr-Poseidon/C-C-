#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

typedef vector<int> vec;

vec all_divisor(int num)
{
	vec ans;
	for(int i=1;i<=sqrt(num);i++)
	{
		if(num%i==0)
		{
			ans.push_back(i);
			if(i!=num/i)
				ans.push_back(num/i);
		}
	}
	sort(ans.begin(),ans.end());
	return ans;
}
int main()
{
	vec ans=all_divisor(5000000);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<endl;
	return 0;
}
