#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N=11,M=110;

int f[N][N][M];
int l,r,P;

int mod(int x,int y)//ȡģ������ʹ��ȡ������ģȫ����������
{
    return (x%y+y)%y;
}

void init()
{
    memset(f,0,sizeof f);//����������ݡ�Ҫ��ʼ����
    
    for(int i=0;i<=9;i++)f[1][i][mod(i,P)]++;//ֻ��һλ����ʱ������
    
    for(int i=2;i<N;i++)//����iλ����
        for(int j=0;j<=9;j++)//���λΪj
            for(int k=0;k<P;k++)//modP������Ϊk
                for(int x=0;x<N;x++)//��һλ������x
                    f[i][j][k]+=f[i-1][x][mod(k-j,P)];
}

int dp(int n)
{
    if(n==0)return 1;//0ģ���κ�������0������һ�ֺϷ�����
    
    vector<int> nums;//ȡ��ÿһλ����
    while(n)nums.push_back(n%10),n/=10;
    
    int ans=0;//ά��������
    int pre=0;//ά��ǰ������ֵĺ�
    
    for(int i=nums.size()-1;i>=0;i--)//����ÿһλ����
    {
        int x=nums[i];//ȡ����Ϊ����
        
        for(int j=0;j<x;j++)//�����λ������С��x�����
            ans+=f[i+1][j][mod(-pre,P)];
        
        pre+=x;//x����ǰ������ֺ�
        
        if(i==0 && pre%P==0)ans++;//����Ҳ��һ�ֺϷ����������
    }
    
    return ans;//���ؽ��
}

int main()
{
    while(cin>>l>>r>>P)//��������
    {
        init();//��ʼ��
        
        cout<<dp(r)-dp(l-1)<<endl;//���
    }
    
    return 0;
}
