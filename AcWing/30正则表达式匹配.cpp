class Solution {
public:
    int n,m;
    vector< vector<int> > f;
    
    bool dp(int x,int y,string& s,string& p)
    {
        if(f[x][y]!=-1) return f[x][y];//�ж��Ƿ��ѹ�
        if(y==m)//�ж��Ƿ�ĩβ
            return f[x][y]= x==n;
        
        bool first_match = x<n && (s[x]==p[y] || p[y]=='.');
        bool ans;
        if(y+1<m && p[y+1]=='*')//y+1��ǰ�����жϣ�������ܻ�Խ��
        {
            //   *==0             *���ھͱ����ж�first_match����
            ans = dp(x,y+2,s,p) || first_match && dp(x+1,y,s,p);
        }
        else
            ans = first_match && dp(x+1,y+1,s,p);//ƥ������������һ���ַ�
            
        return f[x][y]=ans;
    }
    
    bool isMatch(string s, string p) {
        n=s.size();
        m=p.size();
        f=vector< vector<int> >(n+1,vector<int>(m+1,-1));//״̬��ʼ��
        
        return dp(0,0,s,p);
    }
};
