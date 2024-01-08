class Solution {
public:
    int mod = 1e9+7;
    map<pair<int,int>,pair<int,int>>h;
    pair<int,int>solve(vector<string>&board, int i, int j, int n, int m){
        if(i==0 && j==0) return {0,1};
        if(i<0 || j<0 || i>=n || j>=m || board[i][j] == 'X')return {INT_MIN,0};
        if(h.find({i,j})!=h.end())return h[{i,j}];
        int no=0,cnt=0;
        if(board[i][j] != 'S')no=board[i][j]-'0';
        auto a = solve(board, i-1, j, n, m);
        auto b = solve(board, i, j-1, n, m);
        auto c = solve(board, i-1, j-1, n, m);
        int curr = (max(a.first, max(b.first, c.first)))%mod;
        if(curr == a.first)cnt+=a.second;
        if(curr == b.first)cnt+=b.second;
        if(curr == c.first)cnt+=c.second;
        return h[{i,j}] = {(curr+no)%mod, cnt%mod};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        auto ans = solve(board, board.size()-1, board[0].size()-1, board.size(),board[0].size());
        if(ans.first<0)return {0,0};
        return {ans.first%mod,ans.second%mod};
    }
};