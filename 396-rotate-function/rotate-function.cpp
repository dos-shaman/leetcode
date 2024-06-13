class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int total = 0;
        int ans = INT_MIN;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum = sum + (nums[i] * i);
            total += nums[i];
        }

        int k = nums.size()-1;
        ans = max(ans,sum);
        while(k>0){
            sum = sum - (nums[k] * (nums.size()-1));
            sum = sum + (total - nums[k]);
            ans = max(ans,sum);


            k--;
        }

        return ans;
    }
};