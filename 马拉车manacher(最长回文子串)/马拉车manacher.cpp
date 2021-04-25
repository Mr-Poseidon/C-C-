// �ο����� ��https://blog.csdn.net/The_star_is_at/article/details/53354958  
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+10;

char s[N],sn[2*N];
int le[2*N];

void init()
{
	int k=0;
	
	sn[k++]='@';//��ֹԽ�� 
	sn[k++]='#';
	for(int i=0;i<strlen(s);i++)
	{
		sn[k++]=s[i];
		sn[k++]='#';
	}
	sn[k]='\0';//��ֹԽ��
}
int manacher()
{
	//mx-����ұ߽磬id-����ұ߽�ĶԳ����� 
	int mx=0,id;
	int ans=0;//�����´���չ���������Ի��İ뾶��ֱ�ӵ���ԭ���Ļ��ĳ��� 
	for(int i=1;i<strlen(sn);i++)
	{
		// ���ݻ��Ĵ�������
		// 2*id-i = id-(i-id) �ó�i���id�ĶԳ�����j 
		// min(mx-i,le[2*id-i])��len[j]������mx-i���� 
		if(i<mx)le[i]=min(mx-i,le[2*id-i]);
		else le[i]=1;
		
		//�ж������Ƿ���ͬ 
		while(sn[i+le[i]]==sn[i-le[i]])le[i]++;
		
		if(mx<le[i]+i)//�ж��Ƿ񳬳�����ұ߽� 
		{
			mx=le[i]+i;
			id=i;
			ans=max(ans,le[i]);//�������뾶 
		}
	}
	return ans-1;//���İ뾶��������������-1 
}
int main()
{
	cin>>s;
	init();
	cout<<manacher()<<endl;
	//for(int i=0;i<len;i++)cout<<le[i]<<' ';
	return 0;
}
