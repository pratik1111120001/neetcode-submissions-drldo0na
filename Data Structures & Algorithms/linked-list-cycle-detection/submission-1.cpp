/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return false;
        ListNode *start = head, *fast = head;
        while(start != nullptr && fast != nullptr && fast->next != nullptr){
            start = start->next;
            fast = fast->next->next;
            if(start == fast) return true;
        }
        return false;
    }
};
