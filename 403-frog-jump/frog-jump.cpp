class Solution {
public:
    bool solve(int index,int k,vector<int> &stones,unordered_map<int,int> &map,vector<vector<int>> &dp){
        if(dp[index][k] != -1) return dp[index][k];
        if(index == stones.size()-1) return true;
        bool kMinusOneJumps = false;
        if(k>1&&map.find(stones[index] + (k-1))!=map.end()){
            kMinusOneJumps = solve(map[stones[index] + (k-1)],k-1,stones,map,dp);
        }
        bool kJumps = false;
        if(k>0&&map.find(stones[index] + k)!=map.end()){
            kJumps = solve(map[stones[index] + k],k,stones,map,dp);
        }
        bool kPlusOneJumps = false;
        if(map.find(stones[index] + k + 1)!=map.end()){
            kPlusOneJumps = solve(map[stones[index] + k + 1],k+1,stones,map,dp);
        }

        return dp[index][k] = kMinusOneJumps||kJumps||kPlusOneJumps;
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int,int> map;
        vector<vector<int>> dp(stones.size(),vector<int>(stones.size(),-1));
        for(int i = 0;i<stones.size();i++){
            map[stones[i]] = i;
        }
        return solve(0,0,stones,map,dp);
    }
};