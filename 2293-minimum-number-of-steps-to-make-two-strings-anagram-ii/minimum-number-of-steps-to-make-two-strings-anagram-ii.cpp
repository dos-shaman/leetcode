class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> map (26, 0);
        int cnt = 0;
        for (char ch: s) {map[ch-'a']++; cnt++;}
        for (char ch: t) {
            if (map[ch-'a'] > 0) {map[ch-'a']--; cnt--;}
            else cnt++;
        }
        return cnt;
    }
};