class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& A) {
        unordered_map<int, int> pos;
        long long n = A.size(), res = n;
        for (int i = 0; i < n; ++i)
            pos[A[i]] = i;
        sort(A.begin(), A.end());
        for (int i = 1; i < n; ++i)
            if (pos[A[i]] < pos[A[i - 1]])
                res += n - i;
        return res;
    }
};