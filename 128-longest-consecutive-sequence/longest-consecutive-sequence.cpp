class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1)
        {
            return nums.size();
        }
       priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end()); 
       int prev=pq.top();
       pq.pop();
       int ans=1;
       int res=1;
       while(!pq.empty())
       {
        if(pq.top()==prev+1)
        {
            ans++;
            res=max(res,ans);
        }
        else if(pq.top()==prev)
        {
            ans=ans;
            res=res;
        }
        else
        {
            ans=1;
            res=max(res,ans);
        }
        
        prev=pq.top();
        pq.pop();

       }
       return res;
       
    }
};