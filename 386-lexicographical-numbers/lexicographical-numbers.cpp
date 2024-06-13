class Solution {
public:
    // Recursive function to generate lexicographical numbers
    void add(int i, int n, vector<int>& result) {
        // If the current number exceeds n, stop the recursion
        if (i > n) return;
        
        // Add the current number to the result list
        result.push_back(i);
        
        // Try appending digits 0-9 to the current number and recurse
        for (int j = 0; j <= 9; j++) {
            // Compute the new number by appending j
            int newNumber = i * 10 + j;
            
            // Recursively add the new number if it's valid
            add(newNumber, n, result);
        }
    }

    // Main function to generate the lexicographical order list
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        
        // Start the DFS traversal from numbers 1 to 9
        for (int i = 1; i <= 9; i++) {
            add(i, n, result);
        }
        
        return result;
    }
};