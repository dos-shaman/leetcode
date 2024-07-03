class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<=4){
            return 0;
        }
        
        int res=nums[n-1]-nums[3];
        
        res=min(res,nums[n-4]-nums[0]);
        
        res=min(res,nums[n-2]-nums[2]);
        
        res=min(res,nums[n-3]-nums[1]);
        return res;
        
    }
};