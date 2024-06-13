class Solution {
public:
    int getBitMaskValue(string word) {
        int mask = 0;
        for(auto ch: word) {
            mask  = mask ^ (1<<(ch-97));
        }
        return mask;
    }
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        // get bitmask of all startWords and store them in a set
        // iterate over all target words, create bitmask with removing 1 letter at once
        // check that in set 
        unordered_set<int> hashSet;
        for(int i=0; i< startWords.size(); i++) {
            int mask = getBitMaskValue(startWords[i]);
            hashSet.insert(mask);
        }
        int count  = 0;

        for(int i=0; i < targetWords.size(); i++) {
            string temp = targetWords[i];
            int mask = getBitMaskValue(temp);
            for(int j=0; j<targetWords[i].size(); j++)
            {
                int curr = mask ^ (1<< (temp[j]-97));
                if(hashSet.count(curr) > 0)
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};