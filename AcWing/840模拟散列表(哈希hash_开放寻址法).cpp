#include<iostream>
#include<cstring>
using namespace std;

const int N=200003;//����Ѱַ�����ռ�һ�㿪Ԫ�ظ�����2~3��,����Ӧ��Ϊ����(������ͻ�������)
const int null=0x3f3f3f3f;//���������,�������λ��Ϊ��

int h[N];//��ϣ��

int find(int x)//��ѯx��ŵ�λ�û���xӦ�ô�ŵ�λ��
{
    int k=(x%N+N)%N;//��ϣ�㷨
    
    //һֱѰ�ң�ֱ���ҵ�x����nullλ��
    while(h[k]!=null && h[k]!=x)
    {
        k++;
        if(k==N)k=0;//��ͷ
    }
    return k;//���ص�k����Ŀ�����x��λ��,Ҳ�п�����nullλ��(xӦ�ô�ŵ�λ��)
}

int main()
{
    memset(h,0x3f,sizeof(h));//��ʼ��������ϣ��
    int n;
    cin>>n;
    while(n--)
    {
        char op[2];
        int x;
        
        scanf("%s%d",&op,&x);
        
        int k=find(x);//����xӦ�ô�ŵ�λ��
        
        if(op[0]=='I')h[k]=x;//����
        else
        {
            if(h[k]!=null)cout<<"Yes"<<endl;//����λ�ò�Ϊ��,��x�����ڹ�ϣ����
            else cout<<"No"<<endl;
        }
    }
    return 0;
}


