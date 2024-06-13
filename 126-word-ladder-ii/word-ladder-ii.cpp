class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();

        unordered_set<string> uset;
        for(auto const &it:wordList){
            if(it!=beginWord) uset.insert(it);
        }

        queue<string> q;
        q.push(beginWord);

        vector<pair<string,int>> levels;
        int cnt=0;
        bool flag=false;

        while(!q.empty()){
            int sz=q.size();
        
            for(int i=0;i<sz;i++){
                string node=q.front();
                q.pop();

                levels.push_back({node,cnt});
                
                if(node==endWord){
                    flag=true;
                    break;
                }

                for(int i=0;i<node.length();i++){
                    char original=node[i];
                    for(char j='a';j<='z';j++){
                        if(original==j) continue;
                        
                        node[i]=j;
                        if(uset.find(node)!=uset.end()){
                            q.push(node);
                            uset.erase(node);
                        }
                    }
                    node[i]=original;
                }
            }
            if(flag) break;
            cnt++;
        }
        
        vector<vector<string>> ans;

        if(!flag){
            return ans;
        }

        vector<pair<string,int>>::reverse_iterator it=levels.rbegin();

        vector<string> vec;
        dfs(endWord,levels,ans,vec,it,cnt,beginWord);

        return ans;
    }

private:

    void dfs(string str,vector<pair<string,int>> &levels,vector<vector<string>> &ans,vector<string> &vec,vector<pair<string,int>>::reverse_iterator it,int cnt,string &beginWord){
        if(str==beginWord){
            vec.push_back(str);
            reverse(vec.begin(),vec.end());
            ans.push_back(vec);
            reverse(vec.begin(),vec.end());
            vec.pop_back();

            return;
        }
        
        while(it!=levels.rend() && it->second==cnt){
            it++;
        }

        while(it!=levels.rend() && it->second==cnt-1){
            if(isPossible(str,it->first)){
                vec.push_back(str);
                dfs(it->first,levels,ans,vec,it,cnt-1,beginWord);
                vec.pop_back();
            }
            it++;
        }
    }

    bool isPossible(string str1,string str2){
        int n=str1.length();

        int diff=0;
        for(int i=0;i<n;i++){
            if(str1[i]!=str2[i]){
                diff++;
            }

            if(diff>1) return false;
        }

        return true;
    }
};