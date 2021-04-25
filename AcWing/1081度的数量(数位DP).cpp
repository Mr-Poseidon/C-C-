#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N=35;//2e9�Ķ�������32λ��ȡ35����Խ�� 

int f[N][N];//f[i][j]ά����i��������ѡ��j����Ϊ1�����
int l,r,K,B;

void init()//Ԥ���������
{
    //��i����λ����ѡ��j����λΪ1
    for(int i=0;i<N;i++)
        for(int j=0;j<=i;j++)
            if(!j)f[i][j]=1;//һ������ѡҲ��һ�����
            else f[i][j]=f[i-1][j-1]+f[i-1][j];//���Ԫ��1���ԣ���i��ѡ����1�������ٴ�i-1������ѡ��j-1��1����f[i-1][j-1]
                                               //               ��i��û��ѡ��1�����i-1������ѡ��j��1����f[i-1][j]
}
//dp(n)����[0,n]��������д��ڵ����кϷ�����
int dp(int n)
{
    if(n==0)return 0;//�߽����С�0�������һ���Ϸ�������û��
    
    vector<int> nums;//��ÿһλ��������
    while(n)nums.push_back(n%B),n/=B;//ת����B������
    
    int ans=0;//ά���Ϸ�����
    int pre=0;//֮ǰ��ѡ���1�ĸ������տ�ʼһ����û��ѡ
    for(int i=nums.size()-1;i>=0;i--)//����ÿһλ��
    {
        int x=nums[i];//��iλ����
        
        if(x!=0)//x��=0,˵����λ����ѡ��[0,x]
        {
            ans+=f[i][K-pre];//��λѡ0����ʣ�µ�i=n-1λ��ѡ��K-pre��1
            if(x>1)
            {
                if(K-pre-1>=0)ans+=f[i][K-pre-1];//��x>1ʱ����λѡ1�����
                break;//��Ϊֻ�ܳ���0��1����λx>1���Ϸ���ֱ������ѭ��
            }
            else//��λ�պ�Ϊ1
            {
                pre++;
                if(pre>K)break;//����Ҫѡ�������������ѭ��
            }
        }
        
        
        if(i==0 && pre==K)ans++;//���������һλ������ǰ��պ�ѡ��K��1�����β�ѡ1�����һ�����������++
    }
    
    return ans;//���ؽ��
}

int main()
{
    init();//Ԥ����
    
    cin>>l>>r>>K>>B;//����
    
    cout<<dp(r)-dp(l-1)<<endl;//���
    return 0;
}
