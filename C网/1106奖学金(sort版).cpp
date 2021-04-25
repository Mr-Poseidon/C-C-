#include<iostream>
#include<algorithm>
using namespace std;

struct student
{
	int num;
	int a,b,c;
	int sum;
}stu[300];

bool compare(student a,student b)
{
	if(a.sum!=b.sum)
		return a.sum>b.sum;
	else
	{
		if(a.a!=b.a)
			return a.a>b.a;
		else
			return a.num<b.num;
	}
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>stu[i].a>>stu[i].b>>stu[i].c;
		stu[i].num=i+1;
		stu[i].sum=stu[i].a+stu[i].b+stu[i].c;
	}
	
	sort(stu,stu+n,compare);
	
	for(int i=0;i<5;i++)
		cout<<stu[i].num<<" "<<stu[i].sum<<endl;
	return 0;
}
