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
    void invert(TreeNode* par, TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr)
        {
            return;
        }
        if(left != nullptr)
            invert(left,left->left,left->right);
        if(right != nullptr)
            invert(right,right->left,right->right);
    
        par->left = right;
        par->right = left;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        invert(root,root->left,root->right);
        return root;
    }
};
