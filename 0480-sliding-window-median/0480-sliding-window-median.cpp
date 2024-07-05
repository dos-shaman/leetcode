#pragma GCC optimize("O3", "unroll-loops")
auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);

        for (int i = k; ; ++i) {
            res.push_back(((double(*mid) + *prev(mid, 1 - k % 2)) / 2.0));

            if (i == nums.size()) break;

            window.insert(nums[i]);
            if (nums[i] < *mid) --mid;
            if (nums[i - k] <= *mid) ++mid;
            window.erase(window.lower_bound(nums[i - k]));
        }
        
        return res;
    }
};