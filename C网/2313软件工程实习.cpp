#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath> 
using namespace std;

int n,k;
struct mate{
	int s,n;
};
bool cmp(mate a,mate b)
{
	if(a.s==b.s)
		return a.n<b.n;
	else
		return a.s>b.s;
} 
mate m[1002];
int score[27][27];

int main()
{	
	cin>>n>>k;
	if(n==0)return 0;
	
	for(int i=0;i<n;i++)
	{
		int s;
		char ch;
		cin>>s>>ch;
		m[i].s=s;
		m[i].n=(int)(ch-'A');//注意输入为字母编号
	}
		
		 
	for(int i=0;i<k;i++)
		for(int j=0;j<k;j++)
			cin>>score[i][j];

	for(int i=0;i<k;i++)//遍历每支队伍的得分 
	{
		int sum=0;
		double ave;//平均分必为double，否则计算绝对值会产生误差，如85.4，70 
		for(int j=0;j<k;j++)
			sum+=score[j][i];
		
		ave=((double)sum/(double)k);//所有队伍评分的均分,此处不能四舍五入 
		int q=0;//不超过15分的队伍 
		sum=0;
		for(int j=0;j<k;j++)
			//平均分不为double，此处计算绝对值会产生误差，如85.4，70
			if(fabs(ave-score[j][i])<=15)
			{
				sum+=score[j][i];
				q++;
			}
		ave=(int)((double)sum/(double)q+0.5);//实际项目得分，四舍五入 
		
		for(int j=0;j<n;j++)//计算该队伍所有队员的实际得分 
			if(m[j].n==i)//判断所在队伍 
				m[j].s=((double)m[j].s*0.60+(double)ave*0.40+0.5);//计算该队员实际得分,四舍五入 
	}
	
	sort(m,m+n,cmp);
	
	for(int i=0;i<n;i++)//输出结果 
	{
		//if(i)cout<<endl;
		cout<<m[i].s<<" "<<(char)(m[i].n+'A')<<endl;
	}
	return 0;
}
