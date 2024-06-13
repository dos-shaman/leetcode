
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string ans="";
        unordered_map<char,int>mp;
        for(auto it:s) mp[it]++;
        priority_queue<pair<char,int>>q;
        for(auto it:mp){
            q.push({it.first,it.second});
        }

        while(!q.empty()){
            auto it=q.top();
            char ch=it.first;
            int freq=it.second;
            q.pop();
            
            if(freq>repeatLimit){
                int cnt=repeatLimit;
                while(cnt--){
                    ans+=ch;
                }
                freq=freq-repeatLimit;

            if(q.size()<=0) break;
            auto itr=q.top();
            char ch1=itr.first;
            int freq1=itr.second;
            q.pop();

            if(freq1>=1){
                ans+=ch1;
                freq1--;
                if(freq1>0) q.push({ch1,freq1});
            }
    
            if(freq>0){
               q.push({ch,freq});   
              }
            }

            else{
                while(freq--){
                    ans+=ch;
                }
            }
           
        }
        return ans;
    }
};