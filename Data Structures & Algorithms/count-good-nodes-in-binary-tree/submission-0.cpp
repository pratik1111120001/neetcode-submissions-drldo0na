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
    void solve(TreeNode* root, int &ans, int maxi){
        if(root == nullptr) return;
        if(root->val >= maxi) ans++;
        solve(root->left, ans, max(maxi,root->val));
        solve(root->right, ans, max(maxi,root->val));
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        solve(root,ans,-101);
        return ans;
    }
};
