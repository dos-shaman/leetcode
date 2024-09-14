class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int length = 0;
        int maxi = 0;
        for(int i=0; i<nums.size(); i++){
            if(maxi < nums[i]) maxi = nums[i];
        }
        int temp = 0;
        for(int i=0; i < nums.size(); i++){
            if(nums[i] == maxi) temp++;
            else if (temp){
                length = max(temp, length);
                temp = 0;
            }
        }
        
        length = max(temp, length);
        return length; 
    }
};
static const int GMD = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();