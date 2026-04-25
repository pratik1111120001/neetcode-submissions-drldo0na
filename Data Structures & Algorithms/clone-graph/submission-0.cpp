/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> vis;
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;
        if(vis.contains(node)) 
            return vis[node];
        Node* res = new Node(node->val);
        vis[node] = res;
        for(auto it : node->neighbors){
            Node* curr = cloneGraph(it);
            res->neighbors.push_back(curr);
        }
        return res;
    }
};
