class Solution {
public:
    int mod = 1000000007;
int ps[100001] = {};
int sumOfFlooredPairs(vector<int>& nums) {
    long res = 0, max_n = *max_element(begin(nums), end(nums));
    for (auto n : nums)
        ++ps[n];
    vector<pair<int, int>> n_cnt;
    for (auto i = 1; i <= max_n; ++i) {
        if (ps[i])
            n_cnt.push_back({i, ps[i]});
        ps[i] += ps[i - 1];
    }
    for (auto &[n, cnt] : n_cnt)
        for (long f = max_n / n; f > 0; --f)
            res = (res + cnt * f * (ps[min(max_n, (f + 1) * n - 1)] - ps[f * n - 1])) % mod;
    return res;
}
};