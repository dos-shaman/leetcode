class Solution {
public:
    int sumNumbers(TreeNode* root,int tempans = 0) {
        if(root == NULL) return 0;
        tempans=10*tempans+root->val;
        if(root->left == NULL && root->right == NULL) return tempans;
        return sumNumbers(root->left,tempans)+sumNumbers(root->right,tempans);
    }
};