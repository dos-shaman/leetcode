class Solution {
public:
    int minOperations(vector<int>& nums, int t) {
        int mp[32];
        for(auto x: nums) {
            for(int j=0;j<=30;++j) {
                if(x&(1<<j)) {
                    mp[j]++;
                }
            }
        }
        int cnt = 0;
        for(int j=0;j<=30;++j) {
            if(t&(1<<j)) {
                if(mp[j]>0) {
                    mp[j]--;
                }
                else {
                    int q = -1;
                    for(int p=j+1;p<=30;++p) {
                        if(mp[p]>0){
                            q=p;
                            break;
                        }
                    }
                    if (q == -1)return -1;
                    mp[q]--;
                    for(int p=q-1;p>=j; p--) {
                        cnt++;
                        mp[p]+=1;
                    }
                }
            }
            mp[j+1]+=mp[j]/2;
        }
        return cnt;
    }
};