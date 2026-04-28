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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> ans;
        vector<int> curr;
        q.push({root,0});
        if(root == nullptr) return ans;
        int x = 0;
        while(q.size()){
            pair<TreeNode*, int> curr_1 = q.front();
            q.pop();
            if(curr_1.second == x) 
                curr.push_back(curr_1.first->val);
            else{
                ans.push_back(curr);
                curr.clear();
                curr.push_back(curr_1.first->val);
                x = curr_1.second;
            }
            if(curr_1.first->left != nullptr) q.push({curr_1.first->left, curr_1.second+1});
            if(curr_1.first->right != nullptr) q.push({curr_1.first->right, curr_1.second+1});
        }
        if(curr.size()) ans.push_back(curr);
        return ans;
    }
};
