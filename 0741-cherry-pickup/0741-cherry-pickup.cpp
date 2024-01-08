class Solution {
private:
    int n;
    vector<vector<int>> del = {{1, 0, 1, 0}, {0, 1, 0, 1}, {1, 0, 0, 1}, {0, 1, 1, 0}};
    int dp[50][50][50];
    int solve(vector<vector<int>>& grid, int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2;
        if(r1 == n - 1 and c1 == n - 1 and r2 == n - 1 and c2 == n - 1)
            return grid[r1][c1];
        if(dp[r1][c1][r2] != -1)    return dp[r1][c1][r2];
        int ro1, ro2, co1, co2;
        int ret = 0;
        if(r1 == r2 and c1 == c2)   ret += grid[r1][c1];
        else    ret += grid[r1][c1] + grid[r2][c2];
        int mx = -1e9;
        for(auto& d: del) {
            ro1 = r1 + d[0];
            co1 = c1 + d[1];
            ro2 = r2 + d[2];
            co2 = c2 + d[3];
            if(ro1 >= n or co1 >= n or ro2 >= n or co2 >= n or grid[ro1][co1] == -1 
                or grid[ro2][co2] == -1)    continue;
            mx = max(mx, solve(grid, ro1, co1, ro2));
        }
        ret += mx;
        return dp[r1][c1][r2] = ret;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(grid, 0, 0, 0);
        return ans < 0 ? 0 : ans;
    }
};