
class Solution {
public:
bool dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&pathvis,vector<int>&ans){
             vis[node]=1;
             pathvis[node]=1;
             for(int it:adj[node]){
                 if(!vis[it]){
                    if(dfs(it,adj,vis,pathvis,ans)){
                         return true;
                     }
                 }
                 else if(pathvis[it]==1){
                     return true;
                 }
             }
             ans.push_back(node);
             pathvis[node]=0;
             return false;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
         vector<int>adj[numCourses];
        for(int i=0;i<pre.size();i++){
            int x=pre[i][1];
            int y=pre[i][0];
            adj[y].push_back(x);
        }
        vector<int>vis(numCourses);
        vector<int>pathvis(numCourses);
        vector<int>ans;
        for(int i=0;i<numCourses;i++){
      if(!vis[i]){
          if(dfs(i,adj,vis,pathvis,ans)){   
              return {};
            
          }    
            }
        }
        if(ans.size()==numCourses) return ans;
        else return {};
    }
};