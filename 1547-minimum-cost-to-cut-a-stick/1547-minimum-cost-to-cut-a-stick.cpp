class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
       ios_base::sync_with_stdio(false);
       cin.tie(nullptr);
       int bet = 0;
       cuts.push_back(0);
       cuts.push_back(n);
       int c = cuts.size();
       int dp[c][c];
       sort(cuts.begin(),cuts.end());
       for(int cut = bet;cut<=c;cut++){
        for(int i = 0;i<cuts.size();i++){
            if(i+cut+1<cuts.size()){
                if(cut == 0){
                    dp[i][i+1] = 0;
                }
                else{
                    int x = INT_MAX;
                    for(int j = i+1;j<i+cut+1;j++){
                        x = min(x,dp[i][j]+dp[j][i+cut+1]);
                    }
                    dp[i][cut+1+i] = x + (cuts[cut+1+i] - cuts[i]);
                }
            }
        }
       }
       return dp[0][c-1];
    }
};