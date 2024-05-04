class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    void dfs(int i,int j,int m,int n,vector<vector<int>> &grid)
    {
        if(i<0 or j<0 or i>=m or j>=n or grid[i][j]==1)
            return;
        grid[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int x=i+dx[k];
            int y=j+dy[k];
            dfs(x,y,m,n,grid);
        }
        return;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0 or i==m-1 or j==0 or j==n-1)  and grid[i][j]==0)
                {
                     q.push({i,j});
                   // cout<<i<<" "<<j<<endl;
                    grid[i][j]=1;
                }
            }
        }
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int newx=x+dx[k];
                int newy=y+dy[k];
                if(newx<0 or newy<0 or newx>=m or newy>=n or grid[newx][newy]==1)
                    continue;
                grid[newx][newy]=1;
                q.push({newx,newy});
            }
        }
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(grid[i][j]==0)
               {
                   dfs(i,j,m,n,grid);
                   cnt++;
               }
           }
       }
     return cnt;
    }
};