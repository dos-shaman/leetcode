class Solution {
public:
    multiset<long long> lHeap, rHeap;

    void balance() 
    {
        if (lHeap.size() > rHeap.size() + 1) 
        {
            rHeap.insert(*lHeap.rbegin());
            lHeap.erase(prev(lHeap.end()));
        } 
        else if (rHeap.size() > lHeap.size()) 
        {
            lHeap.insert(*rHeap.begin());
            rHeap.erase(rHeap.begin());
        }
    }

    void addNum(int num) 
    {
        if (lHeap.empty() || num <= *lHeap.rbegin()) 
        {
            lHeap.insert(num);
        } 
        else 
        {
            rHeap.insert(num);
        }

        balance();
    }

    void remove(int num) 
    {
        if (num <= *lHeap.rbegin()) 
        {
            lHeap.erase(lHeap.find(num));
        } 
        else 
        {
            rHeap.erase(rHeap.find(num));
        }

        balance();
    }

    double median() 
    {
        if (lHeap.size() == rHeap.size()) 
        {
            return (*lHeap.rbegin() + *rHeap.begin()) / 2.0;
        } 
        else 
        {
            return *lHeap.rbegin();
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;

        for (int i = 0; i < nums.size(); i++) 
        {
            addNum(nums[i]);

            if (i >= k) 
            {
                remove(nums[i - k]);
            }

            if (i >= k - 1) 
            {
                res.push_back(median());
            }
        }

        return res;
    }
};