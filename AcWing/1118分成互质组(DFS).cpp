#include<iostream>
#include<algorithm>
using namespace std;

const int N=15;

int a[N];//ά��ÿһ����
int g[N][N];//g[i][j]ά����i��ĵ�j����
int si[N];//si[i]ά����i�������ĸ���
int n,cnt,ans;//cntά��Ŀǰһ�������˶���������ansά��Ŀǰ��ȫ����������ٵ��������

int gcd(int a,int b)//�����Լ��
{
    return b==0?a:gcd(b,a%b);
}

bool check(int k,int num)//�ж�num������Ƿ�͵�k������ȫ����
{
    for(int i=0;i<si[k];i++)
        if(gcd(num,g[k][i])!=1)
            return false;
    return true;
}

void dfs(int kk)
{
    if(cnt>=ans)return;//��֦����������������ڵ�ǰ�Ĵ𰸡���һ����������Сֵ
    if(kk==n)//�������һ����
    {
        ans=min(ans,cnt);//ά����Сֵ
        return;
    }
    
    for(int i=0;i<cnt;i++)//����ÿһ�飬���ܲ��ܴ�����Ѵ���������
        {
            if(check(i,a[kk]))//������������������ȫ����
            {
                g[i][si[i]++]=a[kk];//�������������������
                dfs(kk+1);//������һ����
                si[i]--;//��i�����ĸ���-1����ȡ�������
            }
        }
        
    //����һ���µ���
    g[cnt][si[cnt]]=a[kk];//�����������
    si[cnt]++;//�������ĸ���+1
    cnt++;//����+1
    
    dfs(kk+1);//������һ����
    
    cnt--;//����-1
    si[cnt]--;//���һ������ĸ���-1
    
    return;
}
int main()
{
    cin>>n;//����
    for(int i=0;i<n;i++)cin>>a[i];
    
    cnt=0;//��ʼ���������
    ans=n;//��ʼ����������ֳ�n��
    
    dfs(0);//�ӵ�0������ʼ����
    
    cout<<ans;//�����
    return 0;
}
