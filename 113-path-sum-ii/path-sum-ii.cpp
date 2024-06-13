class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> currentPath;
        pathSumHelper(root, targetSum, currentPath, result);
        return result;
    }

    void pathSumHelper(TreeNode* root, int targetSum, vector<int>& currentPath,             vector<vector<int>>& result) {
        if (root == nullptr) {
            return;
        }

        currentPath.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr && root->val == targetSum) {
            result.push_back(currentPath);
        }

        pathSumHelper(root->left, targetSum - root->val, currentPath, result);
        pathSumHelper(root->right, targetSum - root->val, currentPath, result);

        currentPath.pop_back();
    }
};