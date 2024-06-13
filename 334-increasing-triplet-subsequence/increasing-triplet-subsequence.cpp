#include <vector>
#include <limits>

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int firstMax = std::numeric_limits<int>::max();
        int secondMax = std::numeric_limits<int>::max();

        for (int num : nums) {
            if (num <= firstMax) {
                firstMax = num;
            } else if (num <= secondMax) {
                secondMax = num;
            } else {
                return true;
            }
        }
        
        return false;
    }
};