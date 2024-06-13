class Solution {
public:
    int f(int l,string s){
        int tmp=0;
        while(l<s.size()){
            tmp=tmp*10+s[l]-'0';
            l++;
        }
        return tmp+1;
    }
    int help(int idx, string &s,int t,vector<vector<int>> &dp){
        if(idx==s.size()) return 0;
        if(dp[idx][t]!=-1) return dp[idx][t];
        int ans=0;
        int ub=t?s[idx]-'0':9;
        for(int i=0;i<=ub;i++){
            if(i==1) ans=ans+((i==ub)?f(idx+1,s):pow(10,s.size()-1-idx))+help(idx+1,s,(t&(i==ub)),dp);
            else ans=ans+help(idx+1,s,t&(i==ub),dp);
        }
        return dp[idx][t]=ans;
    }
    int countDigitOne(int n) {
        string s=to_string(n);
        vector<vector<int>> dp(s.size(),vector<int>(2,-1));
        return help(0,s,1,dp);
    }
};