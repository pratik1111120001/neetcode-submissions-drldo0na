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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start=head;
        ListNode* fast=head;
        ListNode* ans = start;
        n++;
        while(n){
            fast = fast->next,n--;
            if(n && fast == nullptr) 
                return start->next;
        }
        while(fast!= nullptr)
        {
            fast = fast->next;
            start = start->next;
        }
        start->next = start->next->next;
        return ans;
    }
};
