class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                string strj=to_string(nums[j])+to_string(nums[i]);;
                string stri=to_string(nums[i])+to_string(nums[j]);;
                if(strj>stri)swap(nums[j],nums[i]);
            }
            ans+=to_string(nums[i]);
        }
        
        return ans[0]=='0'?"0":ans;
    }
};