/*
����Ļ����������⣨�����������⣩
��������δ�Ż���(n-k+1)(k-1)=nk  --��ֵ֮���ظ��Ƚ� 
���������Ż���  (n)=n            --��ֵ֮��Ƚϵ�ʱ��ֱ���ų����������ظ��ȽϵĿ��� 

�����е� m%v ������ͬ�Ĺ�Ϊһ�飬ÿһ���У���ֵ֮���ƫ����Ϊ w
ÿһ��ֻ��Ҫ����һ�� ����Ʒ������Χ�ڵ����Ž⣬���ƫ���������ɵó�ÿһ��Ľ��

�Ż��Ƚϣ�
 
      δ�Ż���	n*m*s                --mΪ������� 
  �������Ż���	n*m*log(s) 
���������Ż���	n*v*s                --vΪ��Ʒ�����sΪ�������� 
*/ 


#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

const int N=20005;
int dp[N],pre[N],q[N];//��������ά��Ԫ�ص��±� 

int n,m;
int v,w,s;

int main()
{
    cin>>n>>m;
    for(int i=0;i<=m;i++)
        dp[i]=0;
    
    for(int i=1;i<=n;i++)//��Ʒö��
    {
        cin>>v>>w>>s;
        memcpy(pre,dp,sizeof(dp));
        for(int j=0;j<v;j++)//�������ö��
        {
            //���������Ż�����
            int head = 0, tail = -1;
            for (int k = j; k <= m; k += v) 
            {
				// ����
                if (head <= tail && k - s*v > q[head]) ++head;

				// ��ӣ��Ӷ�β��ʼ����С�ڱ�Ԫ�ص�Ԫ��ȥ�� 
                while (head <= tail && pre[q[tail]] - (q[tail] - j)/v * w <= pre[k] - (k - j)/v * w)
                    --tail;
				
				// �����ֵ 
                if (head <= tail)
                    dp[k] = max(dp[k], pre[q[head]] + (k - q[head])/v * w);
				
				// ��� 
                q[++tail] = k;
            }
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}


//-------------------------------------�ָ���---------------------------------------


#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=20010;

/*���������Ż��ص㣺
    q[hh]��ͷ�±꣬��Ϊ �������
    q[tt-1]��β�±꣬��Ϊ �������
    
    pre[ q[hh] ] ��ͷ��ֵ��ά��������ֵ
    pre[ q[tt-1] ] ��β��ֵ��ά��������ֵ
    
    s*v �������
    ע�����������Ż����� �� �������� ���ⲻͬ
        �������ڱ��� k-s*w �������ڶ�����Ż��н��
        ���������ⲻ���������ڶ����� ҲҪ ���ڸ��£���hh<tt,��������Ԫ�ؾ͸���
        
    pre[q[tt-1]] - (q[tt-1]-j)/v*w ���� ��β��ʵ������ֵ
    pre[k] - (k-j)/v*w ���� ĿǰԪ�ص�ʵ������ֵ
    �˴�Ϊ��ԱȽ�
    
    (k-q[hh])/v*w ���� k��q[hh]���ӵļ�ֵ
    
*/

int pre[N],f[N];//ά����������
int q[N],hh,tt;//ά���������С�ά������Ԫ�ص��±�
int n,m;

int main()
{
    cin>>n>>m;
    
    for(int i=0;i<n;i++)
    {
        int v,w,s;
        cin>>v>>w>>s;
        
        memcpy(pre,f,sizeof f);//��¼��һ��
        
        for(int j=0;j<v;j++)//����ƫ��������Ϊ mod v ������
        {
            hh=0,tt=0;
            for(int k=j;k<=m;k+=v)//�����漰������������������Ż�
            {
                //���ӣ�ע���˴�Ҫ<�űȽϳ��ӣ�������==����������
                if(hh<tt && q[hh]<k-s*v)hh++;
                //�������д���β��Ԫ��
                while(hh<tt && pre[q[tt-1]] - (q[tt-1]-j)/v*w <= pre[k] - (k-j)/v*w )tt--;
                //                ���� ��  ��
                if(hh<tt)f[k]=max(f[k],pre[q[hh]]+(k-q[hh])/v*w);
                q[tt++]=k;//���
            }
        } 
    }
    cout<<f[m]<<endl;//������
    return 0;
}
 
