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
    bool balanced = true;
    int depth(TreeNode* root){
        if(root == nullptr) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        if(abs(right - left) > 1) balanced = false;
        return (1 + max(left,right));
    }
    bool isBalanced(TreeNode* root) {
        depth(root);
        return balanced;
    }
};
