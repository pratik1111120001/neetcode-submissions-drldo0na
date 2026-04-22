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
    bool same=true;
    void depth(TreeNode* p, TreeNode* q)
    {
        if(p == nullptr && q == nullptr) return;
        if(p == nullptr || q == nullptr){
            same = false;
            return;
        }
        if(p->val != q->val){
            same = false;
            return;
        }
        depth(p->left,q->left);
        depth(p->right,q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        depth(p,q);
        return same;
    }
};
