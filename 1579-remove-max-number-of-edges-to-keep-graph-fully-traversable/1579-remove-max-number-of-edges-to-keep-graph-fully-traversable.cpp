class Solution {
public:

    int find(int i , vector<int> &parent){
        if(i != parent[i] ){
            parent[i] = find(parent[i] , parent);
        }

        return  parent[i];
    }

    bool union_set(int i , int j , vector<int> &parent){
        int & v1  = parent[i] , &v2 = parent[j];
        int p2 = find(j , parent);
        int p1 = find(i , parent);
        /*if(v1 == i){
            v1 = p2;
            return true
        }
        if(v2 == j){
            v2 =p2;
        }
        */
        if(p1 != p2){
            parent[p1] = p2;
        }else {
            return false;
        }
        return true;

    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        vector<int> parentI(n + 1);
        vector<int> parentJ(n + 1);

        for(int i = 1; i <= n;i++){
            parentI[i] = i;
            parentJ[i] = i;
        }

        int ans = 0, count_i = 0 , count_j = 0;

        for(int i = 0; i< edges.size();i++){
            int from = edges[i][1] , to = edges[i][2];
            if(edges[i][0] == 3){
                bool merge = union_set(from , to , parentI);
                merge &= union_set(from , to , parentJ);

                if(merge){
                    count_i++;
                    count_j++;
                } else{
                    ans++;
                }
            }
        }



        for(int i = 0; i< edges.size();i++){
            int from = edges[i][1] , to = edges[i][2];
            if(edges[i][0] == 1){
                if(!union_set(from , to , parentI)) {
                    ans++;
                }else{
                    count_i++;
                }
            } else if(edges[i][0] == 2){
                if(!union_set(from , to , parentJ)) {
                    ans++;
                }else{
                    count_j++;
                }
            }
        }

        if(count_i < n - 1 || count_j < n - 1) return -1;
        else
            return ans;
    }
};