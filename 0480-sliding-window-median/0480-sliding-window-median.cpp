#define p pair<double, int>
class Solution {
public:
    priority_queue<p> leftMax;
    priority_queue<p, vector<p>, greater<p>> rightMin;
    int l = 0, r = 0;
    vector<double> ans;
    bool balance() {
        bool flag = true;
        // left == right (no. of element) or left can have 1 more
        // if right have more than left
        if (l == r or l == r + 1)
            return true;
        else if (l < r) {
            flag = false;
            leftMax.push(rightMin.top());
            rightMin.pop();
            l++;
            r--;
        }
        // if left have 2 and or more elements than right
        else if (l - r >= 2) {
            flag = false;
            rightMin.push(leftMax.top());
            leftMax.pop();
            r++, l--;
        }
        return flag;
    }
    void addNum(int num, int i) {
        if (leftMax.empty() or num <= leftMax.top().first) {
            leftMax.push({num, i});
            l++;
        } else {
            rightMin.push({num, i});
            r++;
        }
        balance();
    }
    double findMedian(int i) {
        while (!leftMax.empty() and leftMax.top().second <= i) {
            leftMax.pop();
        }
        while (!rightMin.empty() and rightMin.top().second <= i) {
            rightMin.pop();
        }
        balance();

        if (l == r)
            return ((leftMax.top().first + rightMin.top().first) / 2.0);
        else
            return leftMax.top().first;
    }
    void fixInvalidate(int i, vector<int>& nums) {
        // if element to be removed is at top of any heap then pop them
        // else find out in which heap they are hiding and remove size of that heap
        if (nums[i] == leftMax.top().first and leftMax.top().second == i) {
            leftMax.pop();
            l--;
        } else if (nums[i] == rightMin.top().first and
                   rightMin.top().second == i) {
            rightMin.pop();
            r--;
        } else if (nums[i] <= leftMax.top().first) {
            l--;
        } else {
            r--;
        }
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        for (int i = 0; i < k; i++) {
            addNum(nums[i], i);
        }
        ans.push_back(findMedian(-1));
        int i = 0, j = k, n = nums.size();

        while (j < n) {
            // find ith element or adjust it
            fixInvalidate(i, nums);
            addNum(nums[j], j);
            j++;
            // while finding meadian we check if top element is inavlid 
            // if index of that element is less than equal to i (out of window)
            ans.push_back(findMedian(i));
            i++;
        }
        return ans;
    }
};