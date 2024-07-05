class Solution {
    const int MOD = 1000000007;
public:
    int helper(int n,int ch,vector<vector<int>> &dp){
        if(n==0)return 1;
        if(dp[n][ch]!=-1)return dp[n][ch];
        int ans=0;
        if(ch==0){
            ans =(ans +helper(n-1,1,dp))%MOD;
            ans =(ans +helper(n-1,2,dp))%MOD;
            ans =(ans +helper(n-1,3,dp))%MOD;
            ans =(ans +helper(n-1,4,dp))%MOD;
            ans =(ans +helper(n-1,5,dp))%MOD;
        }
        else if(ch==1){
            ans =(ans +helper(n-1,2,dp))%MOD;
        }
        else if(ch==2){
            ans =(ans +helper(n-1,1,dp))%MOD;
            ans =(ans +helper(n-1,3,dp))%MOD;
        }
        else if(ch==3){
            ans =(ans +helper(n-1,1,dp))%MOD;
            ans =(ans +helper(n-1,2,dp))%MOD;
            ans =(ans +helper(n-1,4,dp))%MOD;
            ans =(ans +helper(n-1,5,dp))%MOD;  
        }
        else if(ch==4){
            ans =(ans +helper(n-1,3,dp))%MOD;
            ans =(ans +helper(n-1,5,dp))%MOD;  
        }
        else if(ch==5){
            ans =(ans +helper(n-1,1,dp))%MOD;
        }
        return dp[n][ch]=ans;
    }
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n+1,vector<int>(6,-1));
        return helper(n,0,dp);
    }
};