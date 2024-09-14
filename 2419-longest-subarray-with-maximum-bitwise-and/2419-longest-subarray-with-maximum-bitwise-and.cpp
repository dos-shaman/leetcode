class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int length = 0, maxi = 0;
        for(int i = 0; i < nums.size(); i++) if(maxi < nums[i]) maxi = nums[i];
        int temp = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == maxi) temp++;
            else if(temp){
                length = max(temp, length);
                temp = 0;
            }
        }

        length = max(temp, length);
        return length;
    }
};