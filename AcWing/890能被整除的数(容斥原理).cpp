#include<iostream>
using namespace std;

const int N=20;
typedef long long ll;

/*
    �ݳ�ԭ��պÿ���ת����״̬ѹ���е�����״̬
    ��״̬�е�Ԫ�ظ���Ϊ ���� ʱ�պö�Ӧ�ݳ�ԭ���е� + �����
    ��״̬�е�Ԫ�ظ���Ϊ ż�� ʱ�պö�Ӧ�ݳ�ԭ���е� - �����
*/

int primes[N];//ά����������
int n,m;


int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)cin>>primes[i];
    
    int ans=0;
    for(int i=1;i<(1<<m);i++)//�������е�״̬
    {
        int t=1,cnt=0;//t�����״̬������Ԫ�صĳ˻���cnt����״̬��Ԫ�صĸ���
        for(int j=0;j<m;j++)
        {
            if(1<<j&i)//���ѡ���Ԫ��
            {
                cnt++;//Ԫ�ظ���+1
                
                //�˻��������ݷ�Χ��ֱ�ӽ�����һ��״̬
                //ע�⣺�˴�����ll��������������������
                if((ll)primes[j]*t>n)
                {
                    t=-1;
                    break;
                }
                t*=primes[j];//�������˻�
            }
        }
        
        if(t!=-1)//���˻������ݷ�Χ��
        {
            //�ݳ�ԭ�����ֵĵط�
            //Ԫ�ظ���Ϊ������+��Ϊż����-
            if(cnt%2==1)ans+=n/t;
            else ans-=n/t;
        }
    }
    
    cout<<ans;//������
    return 0;
}
