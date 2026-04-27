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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* curr = ans;
        int carry=0;
        while(l1 != nullptr || l2 != nullptr || carry!=0){
            int canbe = carry;
            if(l1 != nullptr){
                canbe+=l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                canbe+=l2->val;
                l2 = l2->next;
            }
            carry = canbe/10;
            canbe%=10;
            curr->next = new ListNode(canbe);
            curr = curr->next;
        }
        return ans->next;
    }
};
