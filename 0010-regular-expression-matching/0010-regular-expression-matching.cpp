class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        dp[0][0]=true;

        for(int i=1;i<=m;i++)
        {
            if(p[i-1]=='*')
            {
                dp[0][i]=dp[0][i-2];
            }
        }

        for(int index1=1;index1<=n;index1++)
        {
            for(int index2=1;index2<=m;index2++)
            {
                if(s[index1-1]==p[index2-1] || p[index2-1]=='.')
                {
                    dp[index1][index2]=dp[index1-1][index2-1];
                }
                else if(p[index2-1]=='*')
                {
                    bool zero=dp[index1][index2-2];
                    bool one=(index1>0 && (s[index1-1]==p[index2-2] || p[index2-2]=='.')) &&
                                dp[index1-1][index2];
                    
                    dp[index1][index2]=zero||one;
                }
                else
                {
                    dp[index1][index2]=false;
                }
            }
        }
        return dp[n][m];
    }
};