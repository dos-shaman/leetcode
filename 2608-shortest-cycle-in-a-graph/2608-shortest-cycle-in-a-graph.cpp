class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
     map<int,vector<int>>mpp;
     vector<int> par(n,0);
     int distance=10000;
     for(auto i:edges){
        mpp[i[0]].push_back(i[1]);
        mpp[i[1]].push_back(i[0]);
     } 
     for(int i=0;i<n;i++){
        vector<int> dist(n,-1);
        queue<int>q;
        q.push(i);
        dist[i]=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            vector<int>vec=mpp[top];
            for(auto v:vec){
                if(dist[v]==-1){
                    q.push(v);
                    dist[v]=dist[top]+1;
                    par[v]=top;
                }
                else if(par[v]!=top && par[top]!=v){
                    
                    if(dist[top]+dist[v]+1<distance){
                        distance= dist[top]+dist[v]+1;
                    }                                      
                }
            }
        }
        
     }
     return distance==10000?-1:distance;
    }
    
};