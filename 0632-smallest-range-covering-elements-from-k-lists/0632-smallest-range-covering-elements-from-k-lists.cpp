class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<pair<int, int>> all;
        for(int i=0;i<k;i++){
            for(int j=0;j<nums[i].size();j++){
                all.push_back({nums[i][j], i});
            }
        }
        sort(all.begin(), all.end());
        int n=all.size();
        int l=0, r=0, len=1e9;
        vector<int> ans(2);
        unordered_map<int, int> mp;
        while(r<n){
            mp[all[r].second]++;   
                while(mp.size()==k){
                    int L = all[r].first-all[l].first+1;
                    if(L<len){
                        len=L;
                        ans[0]=(all[l].first);
                        ans[1]=(all[r].first);
                    }
                    mp[all[l].second]--;
                    if(mp[all[l].second]==0){
                        mp.erase(all[l].second);
                    }
                    l++;
                }
            r++;
        }
        return ans;
    }
};