class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;

        while(l1 != nullptr || l2 != nullptr)
        {
            int sum = 0;

            if(l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;

            if(sum >= 10)
            {
                carry = 1;
                sum = sum % 10;
            }
            else
            {
                carry = 0;
            }

            cur->next = new ListNode(sum);
            cur = cur->next;   // ✅ move forward
        }

        if(carry == 1)
        {
            cur->next = new ListNode(1);
        }

        return dummy->next;
    }
};