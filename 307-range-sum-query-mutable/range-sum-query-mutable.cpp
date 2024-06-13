#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> PreSum;
    vector<int> nums;

    NumArray(vector<int>& nums_) : nums(nums_) {
        PreSum.resize(nums.size() + 1); 
        PreSum[0] = 0; 
        for(int i = 0; i < nums.size(); i++) {
            PreSum[i+1] = PreSum[i] + nums[i];
        }
    }
    
    void update(int index, int val) {
        int diff = val - nums[index]; 
        nums[index] = val; 
        
        for (int i = index + 1; i < PreSum.size(); i++) {
            PreSum[i] += diff;
        }
    }
    
    int sumRange(int left, int right) {
        return PreSum[right+1] - PreSum[left]; 
    }
};