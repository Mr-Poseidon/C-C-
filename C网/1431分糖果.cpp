#include<iostream>
#include<vector>
using namespace std;

int ans=0;
vector<int> candy;

bool test()//�ж��Ƿ�����Ԫ�ض���� 
{
	//������ͼ 
	/* 
	for(vector<int>::iterator it=candy.begin();it!=candy.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	*/ 
	
	//��һ��Ԫ�ص�ֵ 
	vector<int>::iterator first_element=candy.begin()+1; 
	
	//�ж��Ƿ�����Ԫ�ض���� 
	for(vector<int>::iterator it=candy.begin()+1;it!=candy.end();it++)
	{
		if(*it!=*first_element)
			return false;
	}
	return true;
}
int main()
{
	int n;
	cin>>n;
	candy.resize(n+1,0);//�׸�Ԫ��Ϊ��һ��С���ѵ�һ���ǹ����õ� 
	for(vector<int>::iterator it=candy.begin()+1;it!=candy.end();it++)//���� 
		cin>>*it;
	
	while(!test())
	{
		vector<int>::iterator preit=candy.begin();
		//ʵ�ʵ����������ӵڶ���Ԫ�ؿ�ʼ 
		for(vector<int>::iterator it=candy.begin()+1;it!=candy.end();it++)
		{
			if(*it%2==0)//ż��ʱ 
			{
				*it/=2;//���� 
				*preit+=*it;//��ǰ�� 
			}
			else//����ʱ 
			{
				*it+=1;//����һ�� 
				ans++;
				
				*it/=2;//���� 
				*preit+=*it;//��ǰ�� 
			}
			preit=it;//��¼��ǰ��������Ϊ��һ��������ǰһԪ�� 
		}
		*(candy.end()-1)+=*candy.begin();//ĩβԪ�ؼ���ǰ��� 
		*candy.begin()=0;//��һԪ������ 
	}
	cout<<ans<<endl;//������ 
	return 0;
}
