class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        int n=p.size();
        int ma=1;
        sort(p.begin(),p.end());
        for(int i=0;i<n;i++){
            map <float,int>hash;
            for(int j=i+1;j<n;j++)
                ma=max(ma,
                ++hash[(float)(p[j][1]-p[i][1])/
                        (float)(p[j][0]-p[i][0])]+1);
        }
        return ma;
    }
};