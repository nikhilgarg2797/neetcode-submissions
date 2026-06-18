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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* right = head;
        ListNode* left = head;

        // Move right pointer n steps ahead
        while(n--) right = right->next;

        // If right is null → remove head
        if(right == nullptr) return head->next;

        // Move both pointers
        while(right->next != nullptr) 
        {
            left = left->next;
            right = right->next;
        }

        // Delete nth node
        left->next = left->next->next;
        return head;
    }
};