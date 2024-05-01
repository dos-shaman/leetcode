int rowOperations[] = {0, 0, -1, 1};
int colOperations[] = {1, -1, 0, 0};

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {        
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                }                
            }
        }
        
        int stepCount = 0;
        while(!q.empty()){
            stepCount++;
            
            int size = q.size();
            for(int i=0; i<size; i++){
                auto it = q.front();
                q.pop();
                
                int row = it.first;
                int col = it.second;
                
                for(int k=0; k<4; k++){
                    int nthRow = rowOperations[k] + row;
                    int nthCol = colOperations[k] + col;
                    
                    if((nthRow >=0 && nthRow < n) && (nthCol >=0 && nthCol < m) && grid[nthRow][nthCol] == 0){
                        grid[nthRow][nthCol] = stepCount;
                        q.push({nthRow,nthCol});
                    }
                }
            }
        }
        
        if(stepCount == 1){
            return -1;
        }
        else{
            return stepCount-1;
        }
    }
};
