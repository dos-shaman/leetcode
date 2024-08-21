class Solution {
public:
    string largestPalindrome(int n, int k) {
        if (k == 1) {
            return string(n, '9');
        } 
        
        else if (k == 2) {
            if (n <= 2) {
                return string(n, '8');
            } else {
                return '8' + string(n - 2, '9') + '8';
            }
        } 
        
        else if (k == 3 || k == 9) {
            return string(n, '9');
        } 
        
        else if (k == 4) {
            if (n <= 4) {
                return string(n, '8');
            } else {
                return "88" + string(n - 4, '9') + "88";
            }
        } 
        
        else if (k == 5) {
            if (n <= 2) {
                return string(n, '5');
            } else {
                return '5' + string(n - 2, '9') + '5';
            }
        } 
        
        else if (k == 6) {
            if (n <= 2) {
                return string(n, '6');
            } else if (n == 3) {
                return "888";
            } else if (n == 4) {
                return "8778";
            } else if (n % 2 == 1) {
                int l = n / 2 - 1;
                return '8' + string(l, '9') + '8' + string(l, '9') + '8';
            } else {
                int l = n / 2 - 2;
                return '8' + string(l, '9') + "77" + string(l, '9') + '8';
            }
        } 
        
        else if (k == 8) {
            if (n <= 6) {
                return string(n, '8');
            } else {
                return "888" + string(n - 6, '9') + "888";
            }
        } 
        
        else {
            unordered_map<int, string> dic = {
                {0, ""}, {1, "7"}, {2, "77"}, {3, "959"}, {4, "9779"}, 
                {5, "99799"}, {6, "999999"}, {7, "9994999"},
                {8, "99944999"}, {9, "999969999"}, {10, "9999449999"}, {11, "99999499999"}
            };

            int l = n / 12;
            int r = n % 12; 
            
            string nines = "";
            while(l--) {
                nines += "999999";
            }

            return nines + dic[r] + nines;
        }
    }
};