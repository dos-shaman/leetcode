class Solution {
public:
  static string pal7(string& s, int n){
        //999999=142857*7
        // 10^x=1,3,2,6,4,5,1 (mod 7)  for x=0...6
        const string p7[]={"", "7", "77", "5", "77", "7",
        "", "4", "44", "6", "44","4"};
        auto [q, r]=div(n, 12);
        int pos=(n-1)/2;
        copy(p7[r].begin(), p7[r].end(), s.begin()+pos);
        return s;
    }
    static string largestPalindrome(int n, int k) {
        string s=string(n, '9');
        switch(k){
            case 1: case 3: case 9: 
                return s;
            case 2: 
                s[0]=s.back()='8';
                return s;
            case 4:
                if (n<=4) return string(n, '8');
                s[0]=s[1]=s[n-2]=s[n-1]='8';
                return s;
            case 8:
                if (n<=6) return string(n, '8');
                s[0]=s[1]=s[2]=s[n-3]=s[n-2]=s[n-1]='8';
                return s;
            case 5:
                s[0]=s[n-1]='5';
                return s;
            case 6:
                if (n<=2) return string(n, '6');
                if (n&1){
                    s[0]=s[n/2]=s[n-1]='8';
                    return s;
                }
                // n&1==0
                s[0]=s[n-1]='8';
                s[n/2-1]=s[n/2]='7';
                return s;
            case 7: return pal7(s, n);

        }
        return "";
    }
};