class Solution {
public:
    int dp[1500];
    int dfs(int i,int n,vector<int>&nums){
        if(i>=n)
            return 0;
        auto &res=dp[i];
        if(res!=-1)
            return res;
        
        int choix1=nums[i]+dfs(i+2,n,nums);
        int choix2=dfs(i+1,n,nums);
        return res=max(choix2,choix1);
    
    }
    int rob(vector<int>& nums) {
        //memset(dp,-1,sizeof dp);
        int n=nums.size();
        dp[0]=nums[0];
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        dp[1]=nums[1];
        for(int i=2;i<n;i++){
            dp[i]=dp[i-1];
            for(int j=i-2;j>=0;j--){
                dp[i]=max(dp[i],dp[j]+nums[i]);
            }
        }
        return dp[n-1];
    }
};