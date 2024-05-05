class Solution {
    int alphas[26];
    int find(int x) {
        return alphas[x] == x ? x : (alphas[x] = find(alphas[x]));
    }
public:
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; ++i) alphas[i] = i;
        for (auto e : equations) {
            if (e[1] == '=') alphas[find(e[0] - 'a')] = find(e[3] - 'a'); 
        }
        for (auto e : equations) {
            if (e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a')) return false;
        }
        return true;
    }
};