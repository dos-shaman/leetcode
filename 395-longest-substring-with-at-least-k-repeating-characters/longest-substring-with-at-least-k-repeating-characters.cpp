class Solution {
public:
    unordered_map<char, int> countfreq(string s,
                                       unordered_map<char, vector<int>>& pos) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            pos[s[i]].push_back(i);
            mp[s[i]]++;
        }
        return mp;
    }
    string helper(string s, int k) {
        if (s.size() < k)
            return "";
        unordered_map<char, vector<int>> pos;
        unordered_map<char, int> mp = countfreq(s, pos);
        for (auto [key, value] : mp) {
            if (value < k) {
                int left = 0;
                vector<string> substring(value + 1);
                for (int i = 0; i < value; i++) {
                    substring[i] = helper(s.substr(left, pos[key][i]), k);
                    if (pos[key][i] < s.size()-1)
                        left = pos[key][i] + 1;
                    else
                        left = pos[key][i];
                }
                substring[value] = helper(s.substr(left, s.size()), k);

                string largest = substring[0];
                for (auto str : substring) {
                    if (str.size() > largest.size())
                        largest = str;
                }
                return largest;
                // check the max substring in value+1 splits return the longest
            }
        }
        return s;
    }
    int longestSubstring(string s, int k) { return helper(s, k).size(); }
};
