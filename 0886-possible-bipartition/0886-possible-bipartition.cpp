class Solution {
public:
    bool solve(int s,vector<vector<int>> &g,vector<int> &c,int x){
        if(c[s] != -1 && c[s]!=x)return 0;
        if(c[s]!=-1&&c[s]==x)return 1;
        bool a = true;
        c[s] = x;
        for(auto &i: g[s]){
            a &= solve(i,g,c,1^x);
        }
        return a;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> g(n);
        for(auto &i: dislikes){
            g[i[0]-1].push_back(i[1]-1);
            g[i[1]-1].push_back(i[0]-1);
        }
        vector<int> c(n,-1);
        bool ans = true;
        for(int i = 0; i < n; i++){
            if(c[i]==-1){
                ans &= solve(i,g,c,0);
            }
        }
         return ans;
    }
};