class Solution {
public:

    // Custom comparator function to sort people by height and number of people in front
    static bool compareByBoth(const vector<int>& a, const vector<int>& b) {
        if (a[0] != b[0]) {
            return a[0] < b[0]; // Sort by height (first element) in ascending order if they are different
        }
        return a[1] > b[1];   // Sort by number of people in front (second element) in descending order if heights are the same
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& pep) {
        // Sort the people using the custom comparator
        sort(pep.begin(), pep.end(), compareByBoth);
        
        int n = size(pep); // Get the number of people
        
        // Initialize a 2D vector with all elements as [-1, -1]
        vector<vector<int>> v(n, vector<int>(2, -1));
        
        // Iterate through each person in the sorted list
        for(int i = 0; i < n; ++i) {
            int cnt = -1; // Counter for available positions
            int num1 = pep[i][0]; // Height of the current person
            int num2 = pep[i][1]; // Number of people in front of the current person
            
            // Find the correct position for the current person
            for(int j = 0; j < n; ++j) {
                if(v[j][0] == -1) { // Check if the position is available
                    cnt++;
                }
                if(cnt == num2) { // If the correct position is found
                    v[j][0] = num1; // Place the height
                    v[j][1] = num2; // Place the number of people in front
                    break; // Break out of the loop once placed
                }
            }
        }
        return v; // Return the reconstructed queue
    }
};