class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        vector<vector<array<int, 2>>> graph(values.size());
        for (auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        int res = values[0];
        vector<int> seen(values.size());
        function<void(int, int, int)> dfs = [&](int n, int v, int t) {
            for (auto& [nxt, time] : graph[n]) {
                if (t < time) {
                    continue;
                }

                if (nxt == 0) {
                    res = max(res, v);
                }

                int val = seen[nxt] ? 0 : values[nxt];
                ++seen[nxt];
                dfs(nxt, val + v, t - time);
                --seen[nxt];
            }
        };
        
        seen[0] = 1;
        dfs(0, values[0], maxTime);
        seen[0] = 0;
        return res;
    }
};