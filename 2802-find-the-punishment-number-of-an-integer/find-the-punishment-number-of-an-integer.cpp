class Solution {
public:
    bool fun(string s, int n, int start, int end, int sum) {
        if (sum > n)
            return false;
        if (start == end) {
            if (sum + (s[start] - '0') == n)
                return true;
            return false;
        }
        if(sum == n)
            return true;
        for (int i = start; i <= end; i++) {
            int num = stoi(s.substr(start, i - start + 1));
            if (fun(s, n, i + 1, end, sum + num))
                return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            int t = i * i;
            string s = to_string(t);
            if (fun(s, i, 0, s.length() - 1, 0)) {
                sum += t;
            }
        }
        return sum;
    }
};