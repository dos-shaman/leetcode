class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)  return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if (it)
                temp.push_back(it->val);
            if (!it){
                ans.push_back(temp);
                temp.clear();
                if (!q.empty())
                    q.push(NULL);
            }
            else{
                if (it->left)
                    q.push(it->left);
                if (it->right)
                    q.push(it->right);
            }

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }//Hope you would have got it!
};