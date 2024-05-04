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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> v;
        queue<TreeNode*> q;
        q.push(root);
        bool left_to_right=true;
        while(!q.empty()){
            vector<int> u;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode *curr=q.front();q.pop();
                u.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(left_to_right){
                left_to_right=false;
                v.push_back(u);
            }
            else{
                left_to_right=true;
                reverse(u.begin(),u.end());
                v.push_back(u);
            }
        }
        return v;
    }
};