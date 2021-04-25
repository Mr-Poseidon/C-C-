class Solution {
public:
    
    typedef long long int ll;
    typedef vector<ll> vec;
    typedef vector<vec> mat;
    const int mod=1e9+7;

	
    mat matrix_multi(mat& a,mat& b)//矩阵运算模块 
    {
    	//n为矩阵a的行数，m为矩阵b的列数 
        int n=a.size(),m=b[0].size(); 
        mat c(n,vec(m,0));
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                for(int k=0;k<a[i].size();k++)
                    c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
        return c;
    }
    mat pow_mat(mat& m,ll n)//矩阵快速幂模块
    {
        mat ans( m.size() , vec(m.size(),0) );
        for(int i=0;i<m.size();i++)//构造单位矩阵E 
            ans[i][i]=1;
        
        while(n)
        {
            if(n&1)
                ans=matrix_multi(m,ans);
            n=n>>1;
            m=matrix_multi(m,m);
        }
        return ans;
    }
    int countVowelPermutation(int n) {

        // 转移矩阵 
        // {{0,1,0,0,0},{1,0,1,0,0},{1,1,0,1,1},{0,0,1,0,1},{1,0,0,0,0}};
        mat A(5,vec(5,0));
        A[0][1]=1;
        A[1][0]=1,A[1][2]=1;
        A[2][0]=1,A[2][1]=1,A[2][3]=1,A[2][4]=1;
        A[3][2]=1,A[3][4]=1;
        A[4][0]=1;
        
        // 初始底数矩阵 
        mat ans(5,vec(5,0));
        for(int i=0;i<5;i++)
            ans[i][0]=1;
        
        A=pow_mat(A,n-1);//快速幂计算

        ans=matrix_multi(A,ans);//计算结果 
        
        for(int i=1;i<5;i++)//计算题目结果
            ans[i][0]=(ans[i][0]+ans[i-1][0])%mod;

        return ans[4][0];
    }
};
