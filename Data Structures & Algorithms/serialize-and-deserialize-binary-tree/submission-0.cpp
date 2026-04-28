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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "#";
        string l = serialize(root->left);
        string r = serialize(root->right);
        string ans = "(" + l + ")" + to_string(root->val) + "(" + r + ")";
        return ans; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#") return nullptr;
        string l = "";
        int i=0,cnt=0;
        while(data[i] == '(' || cnt){
            l += data[i];
            if(data[i] == '(') cnt++;
            else if(data[i] == ')') cnt--;
            i++;
        }
        string val1 = "";
        while(data[i] != '(') val1+=data[i],i++;
        string r="";
        while(i<data.size())  r+=data[i],i++;
        int curr = stoi(val1);
        TreeNode* ans = new TreeNode(curr);
        l = l.substr(1,l.size()-2);
        r = r.substr(1,r.size()-2);
        ans->left = deserialize(l);
        ans->right = deserialize(r);
        return ans;
    }
};
