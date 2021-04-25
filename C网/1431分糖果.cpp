#include<iostream>
#include<vector>
using namespace std;

int ans=0;
vector<int> candy;

bool test()//判断是否所有元素都相等 
{
	//测试视图 
	/* 
	for(vector<int>::iterator it=candy.begin();it!=candy.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	*/ 
	
	//第一个元素的值 
	vector<int>::iterator first_element=candy.begin()+1; 
	
	//判断是否所有元素都相等 
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
	candy.resize(n+1,0);//首个元素为第一个小朋友的一半糖果放置点 
	for(vector<int>::iterator it=candy.begin()+1;it!=candy.end();it++)//输入 
		cin>>*it;
	
	while(!test())
	{
		vector<int>::iterator preit=candy.begin();
		//实际迭代器遍历从第二个元素开始 
		for(vector<int>::iterator it=candy.begin()+1;it!=candy.end();it++)
		{
			if(*it%2==0)//偶数时 
			{
				*it/=2;//减半 
				*preit+=*it;//往前加 
			}
			else//奇数时 
			{
				*it+=1;//补充一个 
				ans++;
				
				*it/=2;//减半 
				*preit+=*it;//往前加 
			}
			preit=it;//记录当前迭代器作为下一迭代器的前一元素 
		}
		*(candy.end()-1)+=*candy.begin();//末尾元素加最前面的 
		*candy.begin()=0;//第一元素置零 
	}
	cout<<ans<<endl;//输出结果 
	return 0;
}
