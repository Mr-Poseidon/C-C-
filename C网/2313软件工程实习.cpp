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
		m[i].n=(int)(ch-'A');//ע������Ϊ��ĸ���
	}
		
		 
	for(int i=0;i<k;i++)
		for(int j=0;j<k;j++)
			cin>>score[i][j];

	for(int i=0;i<k;i++)//����ÿ֧����ĵ÷� 
	{
		int sum=0;
		double ave;//ƽ���ֱ�Ϊdouble������������ֵ���������85.4��70 
		for(int j=0;j<k;j++)
			sum+=score[j][i];
		
		ave=((double)sum/(double)k);//���ж������ֵľ���,�˴������������� 
		int q=0;//������15�ֵĶ��� 
		sum=0;
		for(int j=0;j<k;j++)
			//ƽ���ֲ�Ϊdouble���˴��������ֵ���������85.4��70
			if(fabs(ave-score[j][i])<=15)
			{
				sum+=score[j][i];
				q++;
			}
		ave=(int)((double)sum/(double)q+0.5);//ʵ����Ŀ�÷֣��������� 
		
		for(int j=0;j<n;j++)//����ö������ж�Ա��ʵ�ʵ÷� 
			if(m[j].n==i)//�ж����ڶ��� 
				m[j].s=((double)m[j].s*0.60+(double)ave*0.40+0.5);//����ö�Աʵ�ʵ÷�,�������� 
	}
	
	sort(m,m+n,cmp);
	
	for(int i=0;i<n;i++)//������ 
	{
		//if(i)cout<<endl;
		cout<<m[i].s<<" "<<(char)(m[i].n+'A')<<endl;
	}
	return 0;
}
