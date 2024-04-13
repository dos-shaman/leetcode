class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j){
        int m=grid.size();
        int n=grid[0].size();

        if(i<0||i>=m||j<0||j>=n||grid[i][j]==0) 
        return 0;
        grid[i][j]=0;
        return 1+dfs(grid,i+1,j)+dfs(grid,i,j-1)+dfs(grid,i-1,j)+dfs(grid,i,j+1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                res=max(res,dfs(grid,i,j));
                }

            }
        }
        return res;
    }
};