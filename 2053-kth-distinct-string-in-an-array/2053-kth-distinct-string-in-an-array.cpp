class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> st;
        for(int i=0; i<arr.size(); i++){
            ++st[arr[i]];
        }
        for(auto& s: arr){
            if(st[s] == 1 && --k == 0) return s;
        }
        return "";
    }
};