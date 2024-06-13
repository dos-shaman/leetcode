class Solution {
public:
int dp[100005][2][5];
int f(int i,int canbuy,vector<int>&v,int trans)
{
    int n=v.size();
    if(i==n||trans>=2)return 0;
    if(dp[i][canbuy][trans]!=-1)return dp[i][canbuy][trans];
    if(canbuy)
    {
        dp[i][canbuy][trans]=max(-v[i]+f(i+1,0,v,trans),f(i+1,1,v,trans));//if bought or skip for buying
    }
    else
    {
        dp[i][canbuy][trans]=max(v[i]+f(i+1,1,v,trans+1),f(i+1,0,v,trans));// if sold or skip for selling
    }
    return dp[i][canbuy][trans];
}
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return f(0,1,prices,0);
    }
};