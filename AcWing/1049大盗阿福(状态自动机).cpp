#include<iostream>
#include<algorithm>
using namespace std;

const int N=100010;

int f[N][2];//f[i][0]-������f[i][1]-��
int n;

//״̬�Զ������Ϸ��������ʼ��Ϊ0�����Ϸ��������ʼ��Ϊ-INF,����õ㲻�ɵ���

//���β�����max(ǰһ����������)
//��������ǰһ�β���+����Ȩֵ

int main()
{
    int T;
    cin>>T;
    while(T--)//������������
    {
        cin>>n;
        
        //��ʼ��״̬
        f[0][0]=0;//�����ǺϷ���
        f[0][1]=-0x3f3f3f3f;//���ǲ��Ϸ���
        
        for(int i=1;i<=n;i++)//�Զ�������
        {
            int w;
            cin>>w;//����Ȩֵ
            
            f[i][0]=max(f[i-1][0],f[i-1][1]);//����
            f[i][1]=f[i-1][0]+w;//��
        }
        
        cout<<max(f[n][0],f[n][1])<<endl;//������
    }
    return 0;
}
