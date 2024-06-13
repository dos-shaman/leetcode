class Solution {
public:
    int countPoints(string rings) {
        vector<vector<int>> v(10, vector<int>(3,0));
        // r, g, b
        for(int i=0;i<rings.size();i+=2){
            char ring = rings[i];
            int rod = rings[i+1] - '0';
            if(ring=='R'){
                v[rod][0] = 1;
            }
            else if(ring=='G'){
                v[rod][1] = 1;
            }
            else if(ring=='B'){
                v[rod][2] = 1;
            }
        }
        int cnt = 0;
        for(int i=0;i<10;i++){
            bool temp = true;
            for(int j=0;j<3;j++){
                if(v[i][j]==0) temp = false;
            }
            if(temp) cnt++;
        }

        return cnt;
    }
};