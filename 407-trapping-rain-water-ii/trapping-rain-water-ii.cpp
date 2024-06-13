class Solution {
public:
    int trapRainWater(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>visited(m+1 , vector<int>(n+1 , 0));
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;

        for(int i =0 ; i < m ; i++)
        {
            for(int j =0 ; j < n ; j++)
            {
                if(i==0 or i==m-1 or j==0 or j==n-1)
                {
                    pq.push({mat[i][j] , {i,j}});
                    visited[i][j] = 1;
                }
            }
        }
        int maxheight =0 ;
        int ans =0 ;
        while(!pq.empty())
        {
            int val = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            maxheight = max(maxheight , val);
            vector<int>rc = {-1 , 1 , 0 , 0};
            vector<int>cr ={0 , 0 , -1 ,1};
            // ab aap dekhiye 
            for(int i =0 ; i < 4 ;i++)
            {
                int newr = x + rc[i];
                int newc = y + cr[i];
                if(newr >=0 and newr < m and newc >=0 and newc<n and visited[newr][newc] == 0)
                {
                    pq.push({mat[newr][newc],{newr , newc}});
                    visited[newr][newc] = 1;
                    if(maxheight > mat[newr][newc])
                    {
                        ans += (maxheight - mat[newr][newc]);
                    }
                }
            }
        }
        return ans;
    }
};