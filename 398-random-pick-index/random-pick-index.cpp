class Solution {
public:
    map<int , vector<int>> mp ;

    Solution(vector<int>& nums){
        for(int i = 0 ; i < nums.size() ; i++)
          {
            if(mp[nums[i]].size() == 0) 
               {
                 mp[nums[i]].push_back(1);
                 mp[nums[i]].push_back(i);
               }
            else
               {
                 mp[nums[i]].push_back(i) ;
               }
          }
     }
    
    int pick(int target)
     {
        int size = mp[target].size() ;

        int index = mp[target][0] ;
        int res = mp[target][index] ;

        index = (index + 1 )%size ;

        if(index == 0)
          index = 1 ;

        mp[target][0] = index ;
        
          return res ;
     }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */