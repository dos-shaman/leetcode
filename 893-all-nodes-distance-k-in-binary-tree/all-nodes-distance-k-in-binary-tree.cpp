/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent) {
        if(root == NULL)
            return;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if(curr->left) {
                q.push(curr->left);
                parent[curr->left] = curr;
            }

            if(curr->right) {
                q.push(curr->right);
                parent[curr->right] = curr;
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        markParents(root,parent);


        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> visited;


        visited[target] = true;
        q.push(target);
        int currLevel = 0;

        while(!q.empty()) {
            int size = q.size();

            if(currLevel == k) 
                break;

            currLevel++;

            for(int i=0;i<size;i++) {
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }


                if(curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }


                if(parent[curr] && !visited[parent[curr]]) {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
        }


        vector<int> result;

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            result.push_back(curr->val);
        }

        return result;
    }
};