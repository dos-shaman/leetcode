#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        unordered_set<string> seen;
        int swaps = 0;
        
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] != s2[i]) {
                string seq = string(1, s1[i]) + s2[i];
                
                if (seen.find(seq) != seen.end()) {
                    seen.erase(seq);
                    swaps++;
                } else {
                    seen.insert(seq);
                }
            }
        }
        
        if (seen.size() == 1) {
            return -1;
        } else if (seen.size() == 2) {
            return swaps + 2;
        } else {
            return swaps;
        }
    }
};
