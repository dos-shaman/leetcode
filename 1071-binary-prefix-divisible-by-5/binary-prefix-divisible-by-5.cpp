class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int sum = nums[0];
        ans.push_back(nums[0] == 0);
        for(int i = 1;i < nums.size();i++){
            sum = (sum * 2 + nums[i]) % 5;
            ans.push_back(sum % 5 == 0);
        }
        return ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();