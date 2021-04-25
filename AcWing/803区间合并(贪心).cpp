#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<int,int> PII;

int n;
vector<PII> segs;

void merge(vector<PII> &segs)
{
    vector<PII> ans;//��ϲ��������
    
    sort(segs.begin(),segs.end());//����pair����Ĭ����first,��second,��С����
    
    int st=-2e9,ed=-2e9;//��ʼ����
    for(vector<PII>::iterator it=segs.begin();it!=segs.end();it++)
    {
        if(ed < (*it).first)//������������˵���ھ�������Ҷ˵㡢˵�����ཻ
        {
            if(st!=-2e9)ans.push_back({st,ed});//ԭʼ���䲻��¼
            st=(*it).first,ed=(*it).second;//����
        }
        else ed=max(ed,(*it).second);//�ཻ������������Ҷ˵�
    }
    
    if(st!=-2e9)ans.push_back({st,ed});//�ж����һ�����䡢Ҳ���Ա��������
    
    segs=ans;//����
}

int main()
{
    cin>>n;//����
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        segs.push_back({l,r});
    }
    
    merge(segs);//�ϲ�����
    
    cout<<segs.size()<<endl;
    return 0;
}

