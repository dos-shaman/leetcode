void partialSort(vector<int>& v, int pos) {
    int val = v[pos];
    auto pos_it = v.begin() + pos;

    auto it = std::upper_bound(v.begin(), pos_it, val);
    if (it != pos_it) {
        std::copy_backward(it, pos_it, pos_it + 1);
        *it = val;
        return;
    }

    it = std::lower_bound(pos_it, v.end(), val);
    if (it != pos_it) {
        std::copy(pos_it + 1, it, pos_it);
        *(--it) = val;
    }
}

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() < k) {
            return {};
        }

        int mid1, mid2;
        if (k % 2 == 0) {
            mid1 = k / 2 - 1;
            mid2 = k / 2;
        } else {
            mid2 = mid1 = k / 2;
        }

        vector<double> result;
        result.reserve(nums.size() - k + 1);
        vector<int> tmp;
        tmp.insert(tmp.end(), nums.begin(), nums.begin() + k);
        std::sort(tmp.begin(), tmp.end());

        for (int i = 0; i < nums.size() - k; ++i) {
            result.push_back(((double)tmp[mid1] + (double)tmp[mid2]) / 2.0);
            auto it = std::lower_bound(tmp.begin(), tmp.end(), nums[i]);
            *it = nums[i + k];
            partialSort(tmp, std::distance(tmp.begin(), it));
        }
        result.push_back(((double)tmp[mid1] + (double)tmp[mid2]) / 2.0);

        return result;
    }
};