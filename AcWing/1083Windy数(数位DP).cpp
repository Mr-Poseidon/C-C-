#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

const int N=15;

int f[N][N];//f[i][j]ά������iλ�����ҵ�iλΪj�ĺϷ�������
int l,r;

//Ԥ����
void init()
{
    for(int i=0;i<=9;i++)f[1][i]=1;//ֻ��һλ��ʱ��ÿ�������ǺϷ��ġ���Ϊ0����ת�ơ�������������0Ҳ�ǺϷ���
    
    for(int i=2;i<N;i++)//����iλ��
        for(int j=0;j<=9;j++)//���λΪ0
            for(int k=0;k<=9;k++)//����ǰһλ
                if(abs(j-k)>=2)//�Ϸ���ת��
                    f[i][j]+=f[i-1][k];//״̬ת�Ʒ���
}

//����[0,n]�ĺϷ�������
int dp(int n)
{
    if(n==0)return 0;//0���ǺϷ�����
    
    //ȡ��ÿһλ��
    vector<int> nums;
    while(n)nums.push_back(n%10),n/=10;
    
    int ans=0;//ά��������
    int pre=-2;//ά��ǰ��һλ������Ϊ�ʼÿһλ�����Ϸ������Գ�ʼ����-2
    
    for(int i=nums.size()-1;i>=0;i--)//����ÿһλ��
    {
        int x=nums[i];//ȡ����λ��
        
        for(int j=(i==nums.size()-1)?1:0;j<x;j++)//�������λ������Ϊ0��Ҫ��1��ʼö�٣����Ҳ��ܰ���x����
            if(abs(j-pre)>=2)//�����ǰһλ����ľ���ֵ���ڵ���2����Ϊ�Ϸ�
                ans+=f[i+1][j];//���Ϸ���
        
        if(abs(x-pre)>=2)pre=x;//�����λ����ǰһλ��û�г�ͻ����¼��λ��
        else break;//����ֱ�ӽ���
        
        if(i==0)ans++;//����Ǳ��������һλ����˵������Ҳ��һ�ַ���������+1
    }
    
    //���⴦�����а���ǰ�������������ٺ���һ��ǰ���㡢�������ֻ��nums.size()-1λ
    for(int i=1;i<nums.size();i++)
        for(int j=1;j<=9;j++)//ö�����в���ǰ��������
            ans+=f[i][j];
    
    return ans;//���ؽ��
}

int main()
{
    init();//Ԥ����
    
    cin>>l>>r;//����
    cout<<dp(r)-dp(l-1)<<endl;//���
    
    return 0;
}
