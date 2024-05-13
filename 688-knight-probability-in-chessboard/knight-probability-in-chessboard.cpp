class Solution {
public:
    double f(int i,int j,int k,int n,vector<vector<vector<double>>> &dp){
        if(k==0) return 1.0;

        if(dp[i][j][k]!=-1.0) return dp[i][j][k];
        int dx[]={-2,-2,-1,1,2,2,1,-1},dy[]={-1,1,2,2,1,-1,-2,-2};
        double ans = 0.0;
        for(int t=0;t<8;t++){
            int nx=i+dx[t],ny=j+dy[t];
            if(nx>=0 && nx<n && ny>=0 && ny<n){
                ans += f(nx,ny,k-1,n,dp);
            }
        }

        return dp[i][j][k]=ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1,-1.0)));
        double ct=f(row,column,k,n,dp);
        for(int i=0;i<k;i++){
            ct = ct/8;
        }

        return ct;
    }
};