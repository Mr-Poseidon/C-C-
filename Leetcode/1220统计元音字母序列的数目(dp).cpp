class Solution {
public:

	//dp[i][j] - i代表序列的长度，j代表第j个元音字母 
    long long int n,dp[20005][6],mod=1000000007;

    int countVowelPermutation(int n) {
        for(int i=0;i<=5;i++)
            dp[1][i]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i][1]=(dp[i-1][2])%mod;

            dp[i][2]=(dp[i-1][1]+dp[i-1][3])%mod;

            dp[i][3]=(dp[i-1][1]+dp[i-1][2]+dp[i-1][4]+dp[i-1][5])%mod;

            dp[i][4]=(dp[i-1][3]+dp[i-1][5])%mod;

            dp[i][5]=(dp[i-1][1])%mod;
        }

        return (dp[n][1]+dp[n][2]+dp[n][3]+dp[n][4]+dp[n][5])%mod;
    }
};
