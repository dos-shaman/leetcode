class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int n=d.size(),m=d[0].size();
        vector<vector<int>> test(n,vector<int>(m,0));
        int y=((-1)*d[n-1][m-1])+1;
        if(y<=0){
            test[n-1][m-1]=1;
        }else{
            test[n-1][m-1]=y;
        }
        for(int i=m-2;i>=0;i--){
            int x=(test[n-1][i+1]-d[n-1][i]);
            if(x<=0){
                test[n-1][i]=1;
            }else{
                test[n-1][i]=x;
            }
        }
        for(int i=n-2;i>=0;i--){
            int x=(test[i+1][m-1]-d[i][m-1]);
            if(x<=0){
                test[i][m-1]=1;
            }else{
                test[i][m-1]=x;
            }
        }

        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                int curr=d[i][j];
                int right=test[i][j+1];
                int down=test[i+1][j];
                int x= min(right,down) - curr;
                if(x<=0){
                    test[i][j]=1;
                }else{
                    test[i][j]=x;
                }
            }
        }
        return test[0][0];
    }
};