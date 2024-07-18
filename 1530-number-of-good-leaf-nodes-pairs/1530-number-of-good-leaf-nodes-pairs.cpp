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
    int res = 0;
    int countPairs(TreeNode* root, int distance) {
        dfs(root,distance);
        return res;
    }
    vector<int> dfs(TreeNode* root, int d){
        if(!root) return {};
        if(!root->left && !root->right) return {1};
        
        auto left = dfs(root->left,d);
        auto right = dfs(root->right,d);
        
        for(auto x: left)
        for(auto y: right) if(x+y<=d)res++;
        
        vector<int> v;
        for(auto x:left) v.push_back(x+1);
        for(auto x:right) v.push_back(x+1);
        return v;
    }
};

