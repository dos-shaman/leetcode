class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> v(n+1);
        for(auto &i: edges){
            v[i[0]].insert(i[1]);
            v[i[1]].insert(i[0]);
        }
        vector<int> v1;
        for(int i = 1; i <= n; i++){
            if(v[i].size()&1){
                v1.push_back(i);
            }
        }
        if(v1.size() == 0)return true;
        else if(v1.size()==2){
            for(int i = 1; i <= n; i++){
                if(v[v1[0]].count(i)==0&&v[v1[1]].count(i)==0)return true;
            }
            if(v[v1[0]].count(v1[1]) == 0)return true;
        }
        else if(v1.size() == 4){
            if((v[v1[0]].count(v1[1]) == 0 && v[v1[2]].count(v1[3]) == 0)||
               (v[v1[0]].count(v1[2]) == 0 && v[v1[1]].count(v1[3]) == 0)||
               (v[v1[0]].count(v1[3]) == 0 && v[v1[2]].count(v1[1]) == 0)
            )return true;
        }
        return false;
    }
};