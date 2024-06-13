class Solution {
public:
    vector<string> res;
    string semi_res;
    vector<string> restoreIpAddresses(string s) 
    {
        help(s, 0, 0);
        return res;
    }

    void help(string s, int index, int level)
    {
        if(level == 4)
        {
            if(index == s.size()) res.push_back(semi_res);
            return;
        }
        if(level < 4)
        {
            if((s.size()+level-semi_res.size()) > 3*(4-level))return;
        }
        for(int i = index; i < s.size() && i < index+3; i++)
        {
            string temp_str = s.substr(index, i-index+1);
            if(temp_str.size() > 1 && temp_str[0] == '0') return;
            if(stoi(temp_str) > 255) return;
            if(level < 3) temp_str += ".";
            semi_res += temp_str;
            help(s, i+1, level+1);
            semi_res.erase(semi_res.size()-temp_str.size(), temp_str.size());
        }
    }
};