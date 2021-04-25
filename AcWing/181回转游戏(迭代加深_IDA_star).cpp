#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=25;

int g[N];//ά��ͼ
//ά��8����������Ӧ��ֵ���±�
int operate[8][8]={
    {0,2,6,11,15,20,22},
    {1,3,8,12,17,21,23},
    {10,9,8,7,6,5,4},
    {19,18,17,16,15,14,13},
    {23,21,17,12,8,3,1},
    {22,20,15,11,6,2,0},
    {13,14,15,16,17,18,19},
    {4,5,6,7,8,9,10}
};
int center[8]={6,7,8,11,12,15,16,17};//ά���м�Ȧ�ڰ˸���ֵ����Ӧ���±�
int opposite[8]={5,4,7,6,1,0,3,2};//ÿ���������෴����
int path[100];//ά���������������

//����ÿ����һ�β������������ĳ�����е�һ�������ԡ�8-�����������Ĵ��������ǻ���Ҫ�����ٵĲ�������
int f()//��ֵ����
{
    int sum[4]={0};//ά��ÿ�������ֵĴ���
    for(int i=0;i<8;i++)sum[g[center[i]]]++;
    
    int ans=0;//ans����1-3���������г������ε����ĸ���
    for(int i=1;i<=3;i++)ans=max(ans,sum[i]);//������ֵ
    return 8-ans;//���ػ���Ҫ�����ٵĲ�������
}

void operation(int u)//����
{
    //����ÿһ�����������ǰѵ�һ�����ŵ�����桢������ǰ��
    int t=g[operate[u][0]];
    for(int i=0;i<6;i++)g[operate[u][i]]=g[operate[u][i+1]];
    g[operate[u][6]]=t;
}

bool dfs(int depth,int max_depth,int pre)//depthΪĿǰ����ȣ�max_depthΪ�ɵ���������ȣ�pre����ǰһ�����������
{
    if(depth+f()>max_depth)return false;//A*,�����Լ�֦
    if(f()==0)return true;//�������
    
    for(int i=0;i<8;i++)//�����˸��������Ż�����˳�򣬱�֤��С�ֵ���
    {
        if(opposite[i]==pre)continue;//��֦����������������ų���Ч����
        
        operation(i);//����
        path[depth]=i;//��¼��������
        if(dfs(depth+1,max_depth,i))return true;//����
        operation(opposite[i]);//�ָ�����
    }
    return false;
}
int main()
{
    while(cin>>g[0] && g[0])
    {
        for(int i=1;i<24;i++)cin>>g[i];//����
        
        int depth=0;//���
        while(!dfs(0,depth,-1))depth++;//��������
        
        if(depth==0)cout<<"No moves needed";
        else
        {
            for(int i=0;i<depth;i++)cout<<(char)(path[i]+'A');//���·��
        }
        cout<<endl;
        cout<<g[center[0]]<<endl;//����˸������ڵ���
    }
    return 0;
}
