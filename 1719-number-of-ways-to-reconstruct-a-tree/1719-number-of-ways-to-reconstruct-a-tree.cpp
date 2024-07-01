class Solution {
public:
    int DFS(vector<int> &cnt, vector<vector<int>> &Sons, int node, int &res, int depth){
        bool hasDup=false;
        int total=0;
        int orignDepht=depth;
        ++depth;
        for(auto &son:Sons[node]){
            if(cnt[son]==cnt[node]){
                hasDup=true;
                ++total;
                ++depth;
                continue;
            }
           
        }
        for(auto &son:Sons[node]){
            if(cnt[son]==cnt[node]){
                continue;
            }
            total+=DFS(cnt,Sons,son,res,depth);
            if(res==0){
                return 0;
            }
            if(res==2){
                hasDup=true;
            }
        }
        if(total+orignDepht !=cnt[node]){
            res=0;
        }else if(hasDup){
            res=2;
        }else{
            res=1;
        }
        return total+1;
    }
    int checkWays(vector<vector<int>>& pairs) {
       
        vector<int> cnt(501,0);
        int n=0;
      
        for(auto &v:pairs){
            cnt[v[0]]++;
            cnt[v[1]]++;
            n=std::max(v[1]+1,n);
        }
        int validNum=0;
        for(auto &c:cnt){
            if(c){
                ++validNum;
            }
        }
        
        vector<int> Tree(n,-1);
        
        
        for(auto &v:pairs){
            if(cnt[v[1]]==cnt[v[0]]){
                if(Tree[v[1]]==-1 || cnt[Tree[v[1]]]>cnt[v[0]] || Tree[v[1]]>v[0])
                Tree[v[1]]=v[0];
                continue;
            }
            if(cnt[v[1]] > cnt[v[0]] &&
                (Tree[v[0]]==-1 || cnt[v[1]]<cnt[Tree[v[0]]] || (cnt[v[1]]==cnt[Tree[v[0]]] && v[1]<Tree[v[0]] ) )){
                Tree[v[0]]=v[1];                                                                                                                                                                                                                                                                                                                                                                                                                         
            }
            if(cnt[v[0]] > cnt[v[1]] &&
                (Tree[v[1]]==-1 || cnt[v[0]]<cnt[Tree[v[1]]] || (cnt[v[0]]==cnt[Tree[v[1]]] && v[0]<Tree[v[1]] ) )){
                Tree[v[1]]=v[0];                                                                                                                                                                                                                                                                                                                                                                                                                         
            }
        }
      
 
        vector<vector<int>> Sons(n);
      
        int root=-1;
        for(int i=1;i<n;i++){
            if(cnt[i]==0){
                continue;
            }
            if(Tree[i]==-1){
                if(root!=-1){
                    return 0;
                }
                root=i;
            }else{
              Sons[Tree[i]].push_back(i);  
            }
        }
  
        if(cnt[root]!=validNum-1){
            return 0;
        }
       
        int res=0;
         DFS(cnt,Sons,root,res,0);
        return res;
    }
};