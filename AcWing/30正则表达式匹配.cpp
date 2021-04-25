class Solution {
public:
    int n,m;
    vector< vector<int> > f;
    
    bool dp(int x,int y,string& s,string& p)
    {
        if(f[x][y]!=-1) return f[x][y];//判断是否搜过
        if(y==m)//判断是否末尾
            return f[x][y]= x==n;
        
        bool first_match = x<n && (s[x]==p[y] || p[y]=='.');
        bool ans;
        if(y+1<m && p[y+1]=='*')//y+1放前面先判断，否则可能会越界
        {
            //   *==0             *存在就必须判断first_match成立
            ans = dp(x,y+2,s,p) || first_match && dp(x+1,y,s,p);
        }
        else
            ans = first_match && dp(x+1,y+1,s,p);//匹配两个串的下一个字符
            
        return f[x][y]=ans;
    }
    
    bool isMatch(string s, string p) {
        n=s.size();
        m=p.size();
        f=vector< vector<int> >(n+1,vector<int>(m+1,-1));//状态初始化
        
        return dp(0,0,s,p);
    }
};
