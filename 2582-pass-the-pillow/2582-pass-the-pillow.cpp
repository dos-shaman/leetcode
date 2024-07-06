class Solution {
public:
    int passThePillow(int n, int time) {
        int ans=time%(n-1);
        int check=time/(n-1);
        if(check&1) ans=n-ans;
        else ans++;
        return ans;
    }
};