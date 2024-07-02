class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>adj[n];
        vector<int>inDeg(n,0);

        for(int i=0; i<relations.size(); i++) {
            adj[relations[i][0]-1].push_back(relations[i][1]-1);
            inDeg[relations[i][1]-1]++;
        }

        vector<int>prevCoursetime(n,0);
        queue<int>q;
        for(int i=0; i<n; i++) {
            if(!inDeg[i])
            q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int i=0; i<adj[node].size(); i++) {
                inDeg[adj[node][i]]--;
                if(!inDeg[adj[node][i]])
                q.push(adj[node][i]);

                prevCoursetime[adj[node][i]] = max(prevCoursetime[adj[node][i]], prevCoursetime[node]+time[node]);
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            ans = max(ans, prevCoursetime[i]+time[i]);
        }

        return ans;
    }
};