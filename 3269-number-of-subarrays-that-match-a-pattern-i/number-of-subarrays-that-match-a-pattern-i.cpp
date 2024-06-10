class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n=nums.size(), p=pattern.size();
        bool f=1;
        int ans=0;
        for(int i=0;i<n-p;i++){
            int a=i; f=1;
            for(int j=0;j<p;j++){
                if((pattern[j]==1 && nums[i]>=nums[i+1]) || 
                   (pattern[j]==0 && nums[i]!=nums[i+1]) || 
                   (pattern[j]==-1 && nums[i]<=nums[i+1])){
                        f=0;
                       break;
                    }
                i++;
            }
            if(f==1)
                ans++;
            i=a;
        }
        return ans;
    }
};