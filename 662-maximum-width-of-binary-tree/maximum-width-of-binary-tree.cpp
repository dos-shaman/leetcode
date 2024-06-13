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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;

        queue<pair<TreeNode*, long long>> q;
        int ans = 0;
        q.push({root,0});

        while(!q.empty()){
            int size = q.size();
            int mini = q.front().second;
            int extreme_left = 0;
            int extreme_right = 0;

            for(int i =0;i<size;i++){
                long long current = q.front().second - mini;
                TreeNode* node = q.front().first;

                q.pop();

                if(i == 0) extreme_left = current;
                if(i == size-1) extreme_right = current;

                if(node->left) q.push({node->left, 2*current + 1});
                if(node->right) q.push({node->right, 2*current + 2});

            }

            ans = max(ans, extreme_right - extreme_left + 1);

        }

        return ans;
    }
};