#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,m,f[2005];
struct Good
{
    int v,w;
};

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)//��ʼ�� 
		f[i]=0;
    
    vector<Good> goods;
    for(int i=0;i<n;i++)//��ÿһ����Ʒ���ж������Ż����浽�������� 
    {
       int v,w,s;
       cin>>v>>w>>s;
       for(int j=1;j<s;j*=2)//��s�ֳ�2�Ĵη���1 2 4 8 16..... 
       {
           s-=j;
           goods.push_back({j*v,j*w});
       }
       if(s>0)goods.push_back({s*v,s*w});//������2�Ĵη�����ֱ�Ӵ��� 
    }
    
    for(auto good:goods)//01���� 
    {
        for(int i=m;i>=good.v;i--)//���⴦��С��good.v�Ĳ��� 
            f[i]=max(f[i],f[i-good.v]+good.w);
    }
    cout<<f[m]<<endl;
    return 0;
}


/********************************�ָ���***********************************************/ 



#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N=25000;

int v[N],w[N],cnt;//ά���ֽ��������Ʒ��ֵ������
int f[N];//ά������
int n,m;

int main()
{
    cin>>n>>m;
    
    //��ÿ����Ʒ�����Ʒֽ�
    while(n--)
    {
        int vi,wi,si;
        cin>>vi>>wi>>si;//����
        
        //�ֽ�
        for(int i=1;i<=si;i<<=1)
        {
            v[cnt]=vi*i;
            w[cnt]=wi*i;
            si-=i;
            cnt++;
        }
        if(si>0)//ע�������Ĳ���
        {
            v[cnt]=vi*si;
            w[cnt]=wi*si;
            cnt++;
        }
    }
    
    for(int i=0;i<cnt;i++)//01����
        for(int j=m;j>=v[i];j--)
            f[j]=max(f[j],f[j-v[i]]+w[i]);
    
    cout<<f[m]<<endl;//���
    return 0;
    
}
