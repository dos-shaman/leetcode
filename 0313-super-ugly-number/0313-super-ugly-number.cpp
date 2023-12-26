class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        long long uglyNumbers[n + 1];  
        uglyNumbers[0] = 0;  
        uglyNumbers[1] = 1;  

        vector<pair<int, int>> primeIndices;
        for (int i = 0; i < primes.size(); i++) {
            primeIndices.push_back(make_pair(primes[i], 1));
        }

        for (int i = 2; i <= n; i++) {
            long long nextUgly = LLONG_MAX;  
            for (int j = 0; j < primes.size(); j++) {
                nextUgly = min(nextUgly, uglyNumbers[primeIndices[j].second] * (long long)primeIndices[j].first);
            }
            uglyNumbers[i] = nextUgly;  
            
            for (int j = 0; j < primes.size(); j++) {
                if (nextUgly == uglyNumbers[primeIndices[j].second] * (long long)primeIndices[j].first) {
                    primeIndices[j].second++;
                }
            }
        }
        
        return uglyNumbers[n];  
    }
};