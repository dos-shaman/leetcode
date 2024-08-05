class Solution { // 22 ms, faster than 67.87%
public:
    const int INF = 100 * 10000; // maximum distance = N * MAX_POS = 100 * 10^4 = 10^6
    int costs[100][100] = {};
    int memo[100][100] = {};
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(houses.begin(), houses.end());
        memset(memo, -1, sizeof(memo));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int medianPos = houses[(i + j) / 2];
                for (int m = i; m <= j; m++)
                    costs[i][j] += abs(medianPos - houses[m]);
            }
        }
        return dp(houses, n, k, 0);
    }
    int dp(vector<int>& houses, int n, int k, int i) {
        if (k == 0 && i == n) return 0;
        if (k == 0 || i == n) return INF;
        if (memo[k][i] != -1) return memo[k][i];
        int ans = INF;
        for (int j = i; j < n; j++)
            ans = min(ans, costs[i][j] + dp(houses, n, k-1, j + 1));
        return memo[k][i] = ans;
    }
};