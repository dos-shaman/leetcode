class Solution {
public:
    int dp[1005][105][2];
    int f(vector<int>& v, int i, int k, bool on){
        if(i >= v.size()) return 0;
        if(dp[i][k][on] != -1) return dp[i][k][on];
        
        int profit = 0;
        profit = max(profit, f(v, i + 1, k, on));
        if(on) profit = max(profit, v[i] + f(v, i + 1, k - 1, 0));
        else if(k) profit = max(profit, f(v, i + 1, k, 1) - v[i]);
        return dp[i][k][on] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return f(prices, 0, k, 0);    
    }
};