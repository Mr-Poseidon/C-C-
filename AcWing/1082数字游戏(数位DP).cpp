#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N=15;

int f[N][N];//f[i][j]ά����iλ���������λΪjʱ�ĺϷ�������
int l,r;//ά������

void init()
{
    for(int i=0;i<=9;i++)f[1][i]=1;//ֻ��һλ��ʱ��ÿһλ�����ǺϷ���
    
    for(int i=2;i<N;i++)//����iλ
        for(int j=0;j<=9;j++)//���λΪj
            for(int k=j;k<=9;k++)//���ڵ���j�����
                f[i][j]+=f[i-1][k];
}


int dp(int n)
{
    if(n==0)return 1;//0�Ļ�Ҳ��һ�ֺϷ�����
    
    vector<int> nums;
    while(n)nums.push_back(n%10),n/=10;
    
    int ans=0;//ά��������
    int pre=0;//ά��ǰ����һλ�����ʼǰ����һλ��������0
    
    //��λdp�ڱ���ÿһλ����ʱ�򣬶��ǲ���������ģ�����446�������ߵ��ڶ���4�����ܱ�֤�����ÿһ��������С��446��
    for(int i=nums.size()-1;i>=0;i--)//����ÿһλ��
    {
        int x=nums[i];//ȡ����λ��
        
        for(int j=pre;j<x;j++)//����ÿһλ�Ϸ������
            ans+=f[i+1][j];
        
        if(pre>x)break;//���ǰ����λ�����ڱ�λ��������������Ϸ���ֱ������ѭ��
        else pre=x;//�����¼ǰ����λ��
        
        if(i==0)ans++;//���������һλ�������n����Ҳ��һ�����
    }
    
    return ans;//���ط�����
    
}
int main()
{
    init();//Ԥ����
    
    while(cin>>l>>r)cout<<dp(r)-dp(l-1)<<endl;
    
    return 0;
}
