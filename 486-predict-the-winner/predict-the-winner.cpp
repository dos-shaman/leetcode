class Solution {
public:
    int solve(vector<int>& nums,int i,int j,int chance){
        if(i>j) return 0;
        if(chance==0)
            return max(nums[i]+solve(nums,i+1,j,1),nums[j]+solve(nums,i,j-1,1));
        else
            return min(solve(nums,i+1,j,0),solve(nums,i,j-1,0));
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++) sum=sum+nums[i];
        long long one=(long long) solve(nums,0,n-1,0);
        sum=sum-one;
        return(one>=sum);
    }
};