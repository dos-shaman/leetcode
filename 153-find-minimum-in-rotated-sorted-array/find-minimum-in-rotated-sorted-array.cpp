class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size()-1;
        while(s <= e)
        {
            if(nums[s] <= nums[e])
            {
                return nums[s];
            }

            int mid = s + (e-s)/2;

            if(nums[e] < nums[mid])
            {
                if(nums[mid+1] < nums[mid])
                    return nums[mid+1];
                else
                    s = mid+1;
            }
            else
            {
                if(nums[mid-1] > nums[mid])
                    return nums[mid];
                else
                    e = mid-1;
            }
        }
        return -1;
    }
};