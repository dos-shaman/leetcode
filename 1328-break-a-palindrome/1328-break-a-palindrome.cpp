class Solution {
public:
    string breakPalindrome(string palindrome)
    {
    if(palindrome.length()<=1)
    return "";
    for(int i=0;i<palindrome.size()/2;i++)
    {
        if(palindrome[i]!='a')
        {
            palindrome[i]='a';
            return palindrome;
            break;
        }
    }
    palindrome[palindrome.size()-1]='b';
    return palindrome;
    }
};