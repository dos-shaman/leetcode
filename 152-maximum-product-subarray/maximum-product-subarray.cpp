class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int maxi = INT_MIN, n = nums.size();
    long long pref = 1, suff = 1;

    for (int i = 0; i < n; i++) {
        if (pref == 0) pref = 1;
        if (suff == 0) suff = 1;

         // Check for zero to avoid division by zero
        if (nums[i] != 0 && abs(pref) > LLONG_MAX / abs(nums[i])) pref = nums[i];
        else pref *= nums[i];

        if (nums[n - i - 1] != 0 && abs(suff) > LLONG_MAX / abs(nums[n - i - 1])) suff = nums[n - i - 1];
        else suff *= nums[n - i - 1];
        
        long long currentMax = max(pref, suff);
        maxi = max(static_cast<long long>(maxi), currentMax);
    }

    return maxi;





        //Better Approach 

        // int maxi=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     int prod=1;
        //     for(int j=i;j<nums.size();j++){
        //         prod=prod*nums[j];
        //         maxi=max(maxi,prod);       
        //         }
        // }
        // return maxi;




        //Brute Force Approach

        // int maxi=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i;j<nums.size();j++){
        //         int prod=1;
        //         for(int k=i;k<=j;k++) prod=prod*nums[k];
        //         maxi=max(maxi,prod);       
        //         }
        // }
        // return maxi;
    }
};