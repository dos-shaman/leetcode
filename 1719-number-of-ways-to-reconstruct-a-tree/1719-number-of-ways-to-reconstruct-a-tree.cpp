class Solution {
public:
    int checkWays(vector<vector<int>>& P) {
        unordered_map<int, unordered_set<int>> g;
        for (const auto& p : P) {
            int u = p[0], v = p[1];
            g[u].insert(v);
            g[v].insert(u);
        }

        function<int(unordered_set<int>)> helper = [&](unordered_set<int> nodes) {
            unordered_map<int, vector<int>> d;
            int m = nodes.size() - 1;
            for (int node : nodes) {
                d[g[node].size()].push_back(node);
            }

            if (d[m].empty()) return 0;
            int root = d[m][0];

            for (int node : g[root]) {
                g[node].erase(root);
            }

            unordered_map<int, unordered_set<int>> comps;
            unordered_set<int> seen;
            int i = 0;

            function<void(int, int)> dfs = [&](int node, int i) {
                comps[i].insert(node);
                seen.insert(node);
                for (int neib : g[node]) {
                    if (seen.find(neib) == seen.end()) dfs(neib, i);
                }
            };

            for (int node : nodes) {
                if (node != root && seen.find(node) == seen.end()) {
                    dfs(node, i);
                    ++i;
                }
            }

            vector<int> cands;
            for (int j = 0; j < i; ++j) {
                cands.push_back(helper(comps[j]));
            }

            if (find(cands.begin(), cands.end(), 0) != cands.end()) return 0;
            if (find(cands.begin(), cands.end(), 2) != cands.end()) return 2;
            if (d[m].size() >= 2) return 2;
            return 1;
        };

        unordered_set<int> nodes;
        for (const auto& kv : g) {
            nodes.insert(kv.first);
        }

        return helper(nodes);
    }
};
