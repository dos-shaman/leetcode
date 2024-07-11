class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,amount+1);
        dp[0]=0;
        sort(coins.begin(),coins.end());
        for(int i=1;i<=amount;i++)
        {
            for(auto &c:coins)
            {
                if(c>i)break;
                dp[i]=min(dp[i],dp[i-c]+1);
            }
        }
        if(dp[amount]==amount+1)return -1;
        return dp[amount];
    }
};