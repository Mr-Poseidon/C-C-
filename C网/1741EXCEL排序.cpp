#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

struct stu{
	int n;
	string s;
	int score;
};
stu p[100005];

bool cmp1(stu a,stu b)
{
	return a.n<b.n;
}
bool cmp2(stu a,stu b)
{
	if(a.s!=b.s)return a.s<b.s;
	else return a.n<b.n;
}
bool cmp3(stu a,stu b)
{
	if(a.score!=b.score)return a.score<b.score;
	else return a.n<b.n;
}
int main()
{
	int n,f,k=1;
	while(cin>>n>>f && n!=0)
	{
		for(int i=0;i<n;i++)
			cin>>p[i].n>>p[i].s>>p[i].score;
			
		if(f==1)sort(p,p+n,cmp1);
		if(f==2)sort(p,p+n,cmp2);
		if(f==3)sort(p,p+n,cmp3);
		
		cout<<"Case "<<k<<':'<<endl;
		k++;
		
		for(int i=0;i<n;i++)
			printf("%06d %s %d\n",p[i].n,p[i].s.c_str(),p[i].score);
	} 
	return 0;
}
