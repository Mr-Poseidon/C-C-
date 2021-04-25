#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const int N=25;

string word[N];//word[i]ά����i������
int f[N][N];//f[i][j]ά����j�����ʽ��ڵ�i�����ʵĺ��桢����غϲ��ֵĳ���
int cnt[N];//cnt[i]ά����i�����ʵ�ʹ�ô���
int n,ans;
char ch;

void dfs(string s,int k)//����
{
    ans=max((int)s.size(),ans);//�����µĳ���
    
    cnt[k]++;//��k������ʹ�ô���+1
    
    for(int i=0;i<n;i++)//����ÿһ������
        if(f[k][i] && cnt[i]<2)//��i�����ʿ��Խ��ڵ�k�����ʵĺ��桢��ʹ�ô�������2��
            dfs(s+word[i].substr(f[k][i]),i);//ԭ�����ַ���s + ��i�����ʺ͵�k�����ʲ��غϵĲ��֣�ʹ�õ��ǵ�i������
    
    cnt[k]--;//��k������ʹ�ô���-1
}
int main()
{
    cin>>n;//����
    for(int i=0;i<n;i++)cin>>word[i];
    cin>>ch;
    
    for(int i=0;i<n;i++)//����ÿһ�����ʡ��жϵ�j�����ʽ��ڵ�i�����ʺ��桢�غϲ��ֵ���С�����Ƕ���
        for(int j=0;j<n;j++)
        {
            string a=word[i],b=word[j];
            for(int k=1;k<(int)min(a.size(),b.size());k++)//��1��ʼ����
                if(a.substr(a.size()-k,k)==b.substr(0,k))//���ڼ�Ϊ��С����
                {
                    f[i][j]=k;//��¼
                    break;//����ѭ��
                }
                    
        }
        
    for(int i=0;i<n;i++)//����ÿһ������
        if(word[i][0]==ch)//�����ʵ�����ĸ����ͷ����ʼ����
            dfs(word[i],i);
    
    cout<<ans;//������
    return 0;
}
