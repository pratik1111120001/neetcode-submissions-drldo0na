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
    vector<int> rightSideView(TreeNode* root) {
                queue<pair<TreeNode*,int>> q;
        vector<int> ans;
        q.push({root,0});
        if(root == nullptr) return ans;
        int x = 0,y = 0;
        while(q.size()){
            pair<TreeNode*, int> curr_1 = q.front();
            q.pop();
            if(curr_1.second != x){
                ans.push_back(y);
                x = curr_1.second;
            } 
            y = curr_1.first->val;
            if(curr_1.first->left != nullptr) q.push({curr_1.first->left, curr_1.second+1});
            if(curr_1.first->right != nullptr) q.push({curr_1.first->right, curr_1.second+1});
        }
        ans.push_back(y);
        return ans;

    }
};
