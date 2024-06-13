struct Solution {
    int maximumDetonation(vector<vector<int>>& a) {
        int n = (int) a.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                long long dx = a[j][0] - a[i][0];
                long long dy = a[j][1] - a[i][1];
                long long dd = dx * dx + dy * dy;
                if (dd <= 1LL * a[i][2] * a[i][2]) {
                    g[i].emplace_back(j);
                }
            }
        }
        int ans = 0;
        for (int r = 0; r < n; r++) {
            vector<int> b(n);
            auto dfs = [&](auto&& self, int v, int p) -> void {
                b[v] = 1;
                for (int to : g[v]) {
                    if (to == p || b[to]) {
                        continue;
                    }
                    self(self, to, v);
                }
            };
            dfs(dfs, r, -1);
            ans = max(ans, accumulate(b.begin(), b.end(), 0));
        }
        return ans;
    }
};