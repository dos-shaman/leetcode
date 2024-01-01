/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  int findSecondMinimumValue(TreeNode* root) {
    if (root == nullptr)
      return -1;
    return findSecondMinimumValue(root, root->val);
  }

 private:
  int findSecondMinimumValue(TreeNode* root, int mini) {
    if (root == nullptr)
      return -1;
    if (root->val > mini)
      return root->val;

    const int leftMin = findSecondMinimumValue(root->left, mini);
    const int rightMin = findSecondMinimumValue(root->right, mini);

    if (leftMin == -1 || rightMin == -1)
      return max(leftMin, rightMin);
    return min(leftMin, rightMin);
  }
};