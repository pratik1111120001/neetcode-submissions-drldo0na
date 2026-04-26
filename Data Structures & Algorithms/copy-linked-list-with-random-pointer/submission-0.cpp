/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> vis;
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        if(vis.contains(head)) return vis[head];

        Node* curr = new Node(head->val);
        vis[head] = curr;
        curr->next = copyRandomList(head->next);
        curr->random = vis[head->random];
        return curr;
    }
};
