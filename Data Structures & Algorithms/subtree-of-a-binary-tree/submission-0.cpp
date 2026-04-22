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
    bool isSame(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr && subRoot == nullptr) return true;
        if(root == nullptr || subRoot == nullptr) return false;
        if(root->val != subRoot->val) return false;
        return (isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(isSame(root, subRoot)) return true;
        if(root == nullptr) return false;
        bool left = false, right = false;
        left = isSubtree(root->left, subRoot);
        right = isSubtree(root->right, subRoot);
        return left || right;
    }
};
