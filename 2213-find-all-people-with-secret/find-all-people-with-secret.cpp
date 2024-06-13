class Solution {
public:
    vector<int> visTime; // Store the time when a person gets to know the secret
    vector<vector<pair<int, int>>> g; // Undirected graph representing meetings with time info

    // Perform Depth-First Search (DFS) starting from the given node and time
    void solve(int node, int time) {
        for (auto ele : g[node]) {
            // Check if the person can know the secret earlier and the meeting time is valid
            if (visTime[ele.first] > ele.second && ele.second >= time) {
                visTime[ele.first] = ele.second;
                solve(ele.first, ele.second); // Continue DFS with the updated time
            }
        }
    }

    // Find all people who eventually know the secret
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        g.assign(n, vector<pair<int, int>>());
        visTime = vector<int>(n, INT_MAX); // Initialize the time array with maximum values

        // Person 0 and firstPerson know the secret at time 0
        visTime[0] = 0;
        visTime[firstPerson] = 0;

        // Create the graph representing meetings
        for (auto ele : meetings) {
            g[ele[0]].push_back({ele[1], ele[2]});
            g[ele[1]].push_back({ele[0], ele[2]});
        }

        // Apply DFS starting from firstPerson with time 0
        solve(firstPerson, 0);
        // Apply DFS starting from person 0 with time 0
        solve(0, 0);

        // Collect the people who know the secret
        vector<int> res;
        for (int i = 0; i < n; i++)
            if (visTime[i] != INT_MAX) res.push_back(i);
        return res;
    }
};