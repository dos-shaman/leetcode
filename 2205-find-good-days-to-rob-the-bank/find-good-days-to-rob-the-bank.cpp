class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> prefix(security.size());
        prefix[0] = 0;
        vector<int> suffix(security.size());
        suffix[security.size() - 1] = 0;
          //calculating prefix array 
        for (int i = 1; i < security.size(); i++) {
            if (security[i] <= security[i - 1]) {
                prefix[i] = prefix[i - 1] + 1;
            } else {
                prefix[i] = 0;
            }
        }
         // calculating suffix array  
        for (int i = security.size() - 2; i >= 0; i--) {
            if (security[i] <= security[i + 1]) {
                suffix[i] = suffix[i + 1] + 1;
            } else {
                suffix[i] = 0;
            }
        }
        vector<int> ans;
        for (int i = 0; i < security.size(); i++) {
            if (prefix[i] >= time && suffix[i] >= time)
                ans.push_back(i);
        }
        return ans;
    }
};