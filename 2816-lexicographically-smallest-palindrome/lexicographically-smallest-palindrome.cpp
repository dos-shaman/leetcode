class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        int cnt = 0;

        int i = 0;
        int j = n-1;

        while(i<=j){
            if(s[i] != s[j]){
                char ch = min(s[i] - 'a',s[j] - 'a');
                s[i] = s[j] = ch+'a';
                cnt++;
            }
            i++;
            j--;
        }
        return s;
    }
};