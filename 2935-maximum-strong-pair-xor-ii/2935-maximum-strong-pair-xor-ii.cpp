class Trie {
public:
    int count;
    Trie* node[2];
    Trie() {
        count = 0;
        node[0] = node[1] = nullptr;
    }
};

class Solution {
public:
    void insert(Trie* root, int n) {
        for (int i = 21; i >= 0; i--) {
            int bit = (n >> i) & 1; 
            if (!root->node[bit]) {
                root->node[bit] = new Trie();
            }
            root->node[bit]->count++;
            root = root->node[bit];
        }
    }

    void remove(Trie* root, int n) {
        for (int i = 21; i >= 0; i--) {
            int bit = (n >> i) & 1; 
            if (root->node[bit]->count == 1) {
                delete root->node[bit];
                root->node[bit] = nullptr;
                return;
            }
            root->node[bit]->count--;
            root = root->node[bit];
        }
    }

    int nerd(Trie* root, int n) {
        int res = 0;
        for (int i = 21; i >= 0; i--) {
            int bit = (n >> i) & 1; 
            if (root->node[1 - bit]) {
                res |= (1 << i);
                root = root->node[1 - bit];
            } else {
                root = root->node[bit];
            }
        }
        return res;
    }

    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = INT_MIN;
        int i = 0;
        Trie* root = new Trie();
        int n = nums.size();
        for (int j = 0; j < n; j++) {
            while (i < j && nums[j] - nums[i] > nums[i]) {
                remove(root, nums[i]);
                i++;
            }
            insert(root, nums[j]);
            ans = max(nerd(root, nums[j]), ans);
        }
        return ans;
    }
};