#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < n; i++) adj[i] = vector<pair<int,int>>();

        for (auto edge : edges)
        {
            int a =edge[0]; int b = edge[1]; int w = edge[2];
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }

        // find the distances by ignoring edges with unassigned weights
        vector<int> dist (n, 1e9+1);
        dijkstra(source, adj, dist, true, false, false);

        // not possible if shorthest path is the distances by ignoring edges with unassigned weights 
        // is smaller then target because we cannot increase it
        if (dist[destination] < target) {
            return vector<vector<int>>();
        }

        // find disatnces if we treat unassigned edges as edge with weight 1 that is smallest possible weight
        dist.assign(n, 1e9);
        dijkstra(source, adj, dist, false, true, false);

        // if assigning smallest possible weight to all edges results in shorthest path greater then traget then it is not possible
        if (dist[destination] > target) {
            return vector<vector<int>>();
        }

        // find all distances from destination 
        vector<int> dist_from_dest(n, INT_MAX);
        dijkstra(destination, adj, dist_from_dest, false, false, true);

        // execute Dijkstra from source and assign weights as described
        vector<int> distance (n, INT_MAX);
        distance[source] = 0;
        priority_queue<pair<int, int>> max_priority_queue;
        max_priority_queue.push({0, source});
        vector<bool> processed(dist.size(), false);
        vector<vector<int>> assigned_w (n, vector<int>(n, -1));

        while(!max_priority_queue.empty())
        {
            int a = max_priority_queue.top().second; max_priority_queue.pop();

            if (processed[a]) continue;
            processed[a] = true;

            for (auto edge : adj[a])
            {
                int child = edge.first; int w = edge.second;

                if (processed[child]) continue;

                if (w < 0)
                {
                    // if we don't have enough information to assign larger then 1
                    // or if the path through (a,child) is larger then target
                    if (dist_from_dest[child] == INT_MAX || distance[a] + dist_from_dest[child] >= target) w = 1;
                    // if we can assign weight so that the length of path through (a,child) equals target
                    else w = target - distance[a] - dist_from_dest[child];
                    assigned_w[a][child] = w;
                    assigned_w[child][a] = w;
                }

                if (distance[a] + w < distance[child])
                {
                    max_priority_queue.push({-1 * (distance[a] + w), child});
                    distance[child] = distance[a] + w;
                }
            }
        }

        vector<vector<int>> res;
        for (auto edge : edges)
        {
            if (edge[2] != -1) res.push_back(edge);
            else res.push_back({edge[0], edge[1], assigned_w[edge[0]][edge[1]]});
        }

        return res;
    }

    void dijkstra(int source, unordered_map<int, vector<pair<int, int>>>& adj, vector<int>& dist, bool ignore_negative, bool set_negative_to_one, bool set_negative_to_inf)
    {
        dist[source] = 0;
        priority_queue<pair<int, int>> max_priority_queue;
        max_priority_queue.push({0, source});
        vector<bool> processed(dist.size(), false);
        while(!max_priority_queue.empty())
        {
            int a = max_priority_queue.top().second; max_priority_queue.pop();
            if (processed[a]) continue;
            processed[a] = true;

            for (auto edge : adj[a])
            {
                int child = edge.first; int w = edge.second;

                if (set_negative_to_inf && w < 0) w = INT_MAX;

                if (set_negative_to_one && w < 0) w = 1;

                if (ignore_negative && w < 0) continue;

                if (dist[a] != INT_MAX && w != INT_MAX && dist[a] + w < dist[child])
                {
                    max_priority_queue.push({-1 * (dist[a] + w), child});
                    dist[child] = dist[a] + w;
                }
            }
        }
    }
};