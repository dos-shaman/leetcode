class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        unordered_map<long, long> prefix, suffix, preFreq, sufPreq;
        vector<long long> ans(n, 0);


        for(int i=0; i<n; i++) {
            if(prefix.find(arr[i]) != prefix.end()) {
                ans[i] += i*preFreq[arr[i]] - prefix[arr[i]];
            }
 
            preFreq[arr[i]]++;

            prefix[arr[i]] += i ;

        }
        for(int i=n-1; i>=0; i--) {
            if(suffix.find(arr[i]) != suffix.end()) {
                ans[i] += suffix[arr[i]] - i*sufPreq[arr[i]];
            }

            sufPreq[arr[i]]++;

            suffix[arr[i]] += i;

        }

        return ans;
    }
};